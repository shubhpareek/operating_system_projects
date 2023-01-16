        #include <stdlib.h>
        #include <unistd.h>
        #include <sys/stat.h>
        #include <fcntl.h>
        #include <sys/wait.h>
        #include<signal.h>
        #include <stdio.h>
        #include <string.h>
        #include <sys/socket.h>
        #include <arpa/inet.h>
        #include <sys/types.h>

        pid_t pid;

        /*
        removes the newline and space from the beginning and end of a string.
        */
        void
        whitespaceremoval(char * buf) {
                if (buf[strlen(buf) - 1] == ' ' || buf[strlen(buf) - 1] == '\n')
                        buf[strlen(buf) - 1] = '\0';
                if (buf[0] == ' ' || buf[0] == '\n')
                        memmove(buf, buf + 1, strlen(buf));
        }

        //for handling signals 
        void
        handle_sigint(int sig) {
                
                if(pid>0){printf("Caught signal SIGINT in pid = %d\n", getpid());kill(pid, SIGTERM);}
        }

        void
        handle_sigstp(int sig){
                      if(pid>0)  printf("caught signal of type SIGSTOP %d",getpid());
                        //kill(pid,SIGTERM);
                        //exit(0);
        }

        /*
        divides string buf using the delimiter c, and returns the array of strings in arrr
        and the size of the array in pointer iter
        */
        void
        divideBuffer(char ** arrr, int * iter, char * buf,
                const char * c) {
                char * token;
                token = strtok(buf, c);
                int pc = -1;
                while (token) {
                        arrr[++pc] = malloc(sizeof(token) + 1);
                        strcpy(arrr[pc], token);
                        whitespaceremoval(arrr[pc]);
                        token = strtok(NULL, c);
                }
                arrr[++pc] = NULL;
                * iter = pc;
        }


        /*
        executes a single external command
        */
        void
        executeBasic(char ** arrr, int wt) {
                        pid = fork();
                if (pid > 0) {
                        //parent
                        
                       if(!wt) wait(NULL);
                } else {
                        //child
                        execvp(arrr[0], arrr);
                        
                        perror("invalid input"
                                "\n");
                        exit(1);
                }
        }

        /*
        executes commands with pipelining 
        */
        void
        execForpipe(char ** buf, int iter, int wt) { //can support up to 10 piped commandsks
                
               // printf("iter = %d\n",iter);
                if (iter > 10)
                        return;

                int fd[10][2], i, pc;
                char * arrr[100];

                for (i = 0; i < iter; i++) {
                        divideBuffer(arrr, & pc, buf[i], " ");
                        
                        if (i != iter - 1) {
                                if (pipe(fd[i]) < 0) {
                                        perror("pipe creating was not successfull\n");
                                        return;
                                }
                        }
                        if (fork() == 0) { 
                                if (i != iter - 1) {
                                        dup2(fd[i][1], 1);
                                        close(fd[i][0]);
                                        close(fd[i][1]);
                                }

                                if (i != 0) {
                                        dup2(fd[i - 1][0], 0);
                                        close(fd[i - 1][1]);
                                        close(fd[i - 1][0]);
                                }
                                if(iter-1==i) // if pipelining with redirection is there 
                                {
                                        //perror("ldjflka");
                                        //perror(arrr[0]);
                                        //perror(arrr[pc-2]);
                                        

                                        if( pc>2 && strstr(arrr[pc-2],">>>"))
                                        {
                                                //perror("dfalj");
                                                //perror(arrr[pc-1]);
                                                int  fdd = open(arrr[pc-1], O_WRONLY | O_CREAT  | O_TRUNC , 0666 );
                                                dup2(fdd, 1);
                                                arrr[pc-2]=NULL;
                                        }
                                       else if( pc>2  && strstr(arrr[pc-2],"&>>"))
                                        {
                                                //perror("fdlj");
                                                int  fdd = open(arrr[pc-1], O_WRONLY | O_CREAT  | O_TRUNC , 0666 );
                                                dup2(fdd, 2);
                                                dup2(fdd, 1);
                                                arrr[pc-2]=NULL;
                                        }
                                }
                                //perror(arrr[0]);
                                execvp(arrr[0], arrr);
                                perror("invalid input ");
                                exit(1);  
                        }
                        if (i != 0) { 
                                close(fd[i - 1][0]);
                                close(fd[i - 1][1]);
                        }
                       if(!wt) wait(NULL);
                }
        }

        /*
        executes with redirection
        */
        void
        execIO(char ** buf, int iter, int mode , int wt) {
                int pc, fd;
                char * arrr[100];
                whitespaceremoval(buf[1]);
                divideBuffer(arrr, & pc, buf[0], " ");
                pid = fork();
                if (pid == 0) {

                        switch (mode) {
                        case 0:
                                fd = open(buf[1], O_RDONLY);
                                break;
                        case 1:
                                fd = open(buf[1], O_WRONLY | O_CREAT  | O_TRUNC , 0666 );
                                break;
                        case 2:
                                fd = open(buf[1], O_WRONLY | O_APPEND | O_CREAT  | O_TRUNC , 0666 );
                                break;
                        case 3:
                                fd = open(buf[1], O_WRONLY | O_CREAT  | O_TRUNC , 0666 );
                                break;
                        default:
                                return;
                        }

                        if (fd < 0) {
                                perror("cannot open file\n");
                                return;
                        }

                        switch (mode) {
                        case 0:
                                dup2(fd, 0);
                                break;
                        case 1:
                                dup2(fd, 1);
                                break;
                        case 2:%s>>
                                dup2(fd, 1);
                                break;
                        case 3:
                                dup2(fd, 2);
                                dup2(fd, 1);
                                break;  wait(NULL);
                        default:
                                return;
                        }
                        execvp(arrr[0], arrr);
                        perror("invalid input ");
                        exit(1); 
                }
               if(!wt) wait(NULL);
        }

        /*
        shows help
        */
        void
        Help() {
                printf("u can exit by typing exit ");
        }

        int
        main(char ** arrr, int argc) {
                char buf[500], * buffer[100], buf2[500], buf3[500], * arrrs1[100],
                        * arrrs2[100], * token, cwd[1024];
                int iter = 0;
                printf("\tSHELL  \n this shell was implemented by 112001039 and 112001054 \n this shell handles redirection , pipelining ,background execution ,built_in commands,also signals\nplease avoid UNNECESSARY SPACES  "
                        "\n\n\n");
                signal(SIGINT, handle_sigint);// handles ctrl c signal 
                signal(SIGTSTP, handle_sigstp);
                //signal(SIGTSTP,handle_sigstp);
                
                while (1) {
                        int wt=0;  
                        //print current Directory
                        if (getcwd(cwd, sizeof(cwd)) != NULL)
                                printf("%s>>", cwd);
                        else
                                perror("getcwd failed\n");

                        //read user input
                        fgets(buf, 500, stdin); //buffer overflow cannot happenc
                        if(buf[strlen(buf)-2]=='&')
                        {
                                wt =1 ;
                                //printf("HELEL\n");
                                buf[strlen(buf)-2]='\0';

                        }
                        // write(1, ">> ", 4);
                        // //scanf("%s",inp);
                        // //fflush(1);
                        // read(0,buf,500);//space will not workd
                        // printf("len = %d\n",strlen(buf));
                        // buf[strlen(buf)-1]='\0';

                        //check if there is no pipe , redirection , background
                        if (strstr(buf, "||")) { //divide pipe commands
                                divideBuffer(buffer, & iter, buf, "||");
                                execForpipe(buffer, iter, wt);
                        } else if (strstr(buf, "&>>")) { //redirect from stderr to file
                                divideBuffer(buffer, & iter, buf, "&>>");
                                if (iter == 2)
                                        execIO(buffer, iter, 3 , wt);
                                else
                                        printf("error , usage : cmd < file \n");
                        } else if (strstr(buf, "<<<")) { //redirect file to input
                                divideBuffer(buffer, & iter, buf, "<<<");
                                if (iter == 2)
                                        execIO(buffer, iter, 0 , wt);
                                else
                                        printf("error , usage : cmd < file \n");
                        } else if (strstr(buf, ">>>")) { //overwrites output to file
                                divideBuffer(buffer, & iter, buf, ">>>");
                                if (iter == 2)
                                        execIO(buffer, iter, 1, wt);
                                else
                                        printf("error , usage : cmd > file \n");
                        } else {

                                divideBuffer(arrrs1, & iter, buf, " ");
                                if (strstr(arrrs1[0], "cd")) { //cd builtin command
                                        
                                        if(iter==1||(*arrrs1[1])=='\n'||(*arrrs1[1])=='\0' ){
                                                char home[]="/home";
                                                chdir(home);
                                        }
                                        else {chdir(arrrs1[1]);}
                                } else if (strstr(arrrs1[0], "help")||strstr(arrrs1[0], "help ")||strstr(arrrs1[0], "help  ")||strstr(arrrs1[0], "help   ")) { //help builtin command
                                        Help();
                                } else if (strstr(arrrs1[0], "exit")||strstr(arrrs1[0], "exit ")||strstr(arrrs1[0], "exit  ")||strstr(arrrs1[0], "exit   ")) { //exit builtin command
                                        exit(0);
                                } else
                                {
                                        executeBasic(arrrs1, wt); // remaining ones 
                                        // wait(0);
                                }
                        }
                }

                return 0;
        }

