

# Assignment 1 (deadline: 13-Sep 2022 23:59 hrs)


## Instructions

1.  This \`questions.md\` files is a Markdown files.
    Markdown is a simple markup
    language that you can use to quickly format text documents.
    The basic syntax of Markdown to achieve headings, subheadings,
    bullets, numbered lists, paragraphs, and so on can be found in
    this link: <https://www.markdownguide.org/basic-syntax/>

2.  When you have answered all the questions given in this file,
    commit your changes, and push it back to your bitbucket repo.


## Questions

1.  ****[5 marks]**** The folder `lab1/groups` has two files: (i)
    `students_list.csv` that contains the roll numbers of the students who have
    registered for a course, and (ii) `responses.csv` that contains the details
    of the groups in which the students wish to do their labs.
    
    Write a SHELL (bash) script that does the following:
    
    1.  Generate a group id for each group, where the group id is
        `<ROLLNO1>_<ROLLNO2>` (with `<ROLLNO1>` is less than `<ROLLNO2>`). If a
        group has only one member, then the group id is simply `<ROLLNO1>` (no \_
        as suffix). ROLLNO1, ROLLNO2 are roll numbers of students (and hence
        integers). NOTE: the output not contain duplicate entries for group ids.
    
    2.  Print the duplicate roll numbers to <stderr> with appropriate error
        message.
    
    3.  All roll numbers should be valid (corresponds to a student who has
        registered in this course). Print the group id if this is not the case
        (again with appropriate error message).
    
    4.  Print the list of roll numbers who have registered for this course but
        have not responded to the form (not part of any group) with an
        appropriate error message.

2.  ****[10 marks]**** The folder `lab1/dedup/inputs` has some files that contain
    information about the marks secured by some students in a few subjects.
    Since a lot of such files may be generated in future, you wish to save disk
    space. Write a shell script `dedup.sh` that takes a directory name as an
    input argument, finds all regular files immediately under this directory
    that are duplicates, and replaces the duplicates with soft-links.
    
    NOTE:
    
    1.  The filename of the duplicates should remain same (before and after
        replacing them with soft links). Your script should not search for
        duplicates recursively.
    
    2.  The original files that is the one that is lexicographically first.
    
    3.  If there are more than one duplicate, the duplicates should continue to
        link to the original (lexicographically first) file only.
    
    4.  If the script is not given any input argument, it is assume the current
        working directory as its input.
    
    5.  The filenames can contain special characters such as "\*", spaces, "~",
        and leading "-". f. Your script should ignore all non-regular files such
        as links, pipes, directories

3.  ****[20 marks]**** Build you custom command shell. You shell should be able to
    accept commands from the user and execute it (just the bash that we saw in
    the lab).
    
    You custom shell should be able to support the following:
    
    1.  Built-in commands: `cd`, `pwd`, `exit` (close your custom shell itself).
    
    2.  Accept commands (names of executables that are existing on the file
        system), and execute them in both the foreground mode (shell waits for
        the execution of the command to complete), and the background mode
        (where shell does not wait for the command to complete). The suffix `&`
        is used to execute a command in the background mode.
    
    3.  Support I/O redirection using `<<<`, `>>>`, and `&>>` operators.
    
    4.  Support command pipelines using `||` (custom) operator.
    
    5.  Control the execution of the commands by interrupting an execution or
        terminating the execution of a command (support `SIGINT`, `SIGSTP`, and
        `SIGCHLD`).

