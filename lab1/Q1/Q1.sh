#the answer will be in ans.txt , duplicates will be printed to stderr , people who didn't respond will be printed on shell itself , 
#and people who have responded but are not in student list their groupid's will be printed to shell
#
touch temp2.txt
touch temp3.txt
touch temp4.txt

#will contain group ids finally 
touch ans.txt

touch alien.txt
touch alien2.txt

touch check.txt
touch rand.txt 
touch errfile.txt

cat students_list.csv > temp2.txt
cat students_list.csv > temp4.txt
true > errfile.txt
true > ans.txt
true > alien.txt
echo "Atleast one of the student in these groups were not in the student list" > alien2.txt

#first we remove all unnecessary details from responses.csv and store it  in check.txt 
cut -d',' -f3,4 responses.csv | sed '1d' | sed 's/,""//g' | sed 's/"//g' | sed 's/,/ /g' | awk '{ if (!$2)print $1 ;else if ($1<$2) print  $1 "\t" $2 ; else print $2 "\t" $1 ; }' | sort |uniq -u > check.txt


#now we iterate on each line of check.txt and find the group id of people who are not in student list , and store it in alien.txt

cat check.txt | while read LINE; do 
	#echo $LINE
	for i in $LINE 
	do 
		if [ $(grep $i students_list.csv | wc -l ) == 0 ]
		then
			echo $LINE >> alien.txt
			break
		fi
	
	done
done

#this code converts the group in formation to group key .
	sed 's/ /_/g' alien.txt >> alien2.txt


# by this code we find students who have not responded and remove them from list of students in temp2
#errfile.txt contains list of students who did not respond to form
for i in $(cat students_list.csv)
do 
	if [ $(grep $i check.txt | wc -l ) == 0 ]
	then 
		echo $i >> errfile.txt
		sed  "s/${i}/ /g"  temp2.txt > temp3.txt
		cat temp3.txt > temp2.txt
	fi
done

#by this code we find groups of students who have responded more than once , and remove them from list of students in temp2
#so finally temp2 will contain list of students who responded exactly once 
for i in $(cat students_list.csv)
do 
	if [ $(grep $i check.txt | wc -l ) -gt 1 ]
	then 	
	grep $i check.txt > rand.txt
		for j in $(cat rand.txt)
		do 
 
			sed  "s/${j}/ /g"  temp2.txt > temp3.txt
			cat temp3.txt > temp2.txt
#			printf "1" > temp4.txt 			
		done
	fi
done


# to convert correct groups to group keys , ans.txt will contain final answer 
for i in $(cat temp2.txt)
do 
	grep $i check.txt | sed 's/\t/_/g' >> ans.txt
done

# now we remove all the students in temp2(correct students ) from temp4 
for i in $(cat temp2.txt)
do 
	sed "s/${i}//g" temp4.txt > temp3.txt
	cat temp3.txt > temp4.txt
done

# now we remove from temp4 the students who didnot respond , so finally temp4 will contain students who responded more than once 
for i in $(cat errfile.txt)
do 
	sed "s/${i}//g" temp4.txt > temp3.txt
	cat temp3.txt > temp4.txt
done

#now we just print the required errors to stderr
#errfile.txt contains list of students who did not respond to form
for i in $(cat errfile.txt)
do 
	 echo "${i} did not fill the form" 
done


#temp4 contains list of students whose group has atleast one member who responded more than once 
for i in $(cat temp4.txt)
do
	>&2 echo "either ${i} or his partner filled the form more than once"
done 

#alien2.txt contains group id's of students who are not in student list 
cat alien2.txt

rm temp2.txt
rm temp3.txt
rm temp4.txt

rm alien.txt
rm alien2.txt

rm check.txt
rm rand.txt 
rm errfile.txt




