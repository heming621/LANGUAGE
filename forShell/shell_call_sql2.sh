#! /bin/bash
if [ $# -ne 2 ];then
   echo "Pls enter parameters:db_name, table_name!!!"
   exit;
fi

# Define log
TIMESTAMP=$(date +%Y%m%d-%H%M%S) #get current time
LOG=call_sql_${TIMESTAMP}.log
echo "Start execute sql statement at $(date).">>${LOG}

# execute sql stat  
mysql -uroot  -p123456 -e "

show databases;

tee /tmp/temp.log  
use $1  
select * from $2 limit 40;  
delete from $2 where date <= date_sub(date(now()),interval 1 month);
select * from $2 limit 40; 
notee  
quit "  
  
echo -e "\n">>${LOG}  
echo "below is output result.">>${LOG}  
cat /tmp/temp.log>>${LOG}  
echo "script executed successful.">>${LOG}  
exit;  
