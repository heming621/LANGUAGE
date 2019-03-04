#! /bin/bash
if [ $# != 3 ];then
  echo "Pls enter local_dbname, other_host, other_host_dbname";
  exit;
else
  mysqldump -uroot -p123456 $1 | ssh $2 mysql -uroot -p12345678 $3
fi


#mysqldump -uroot -p123456 gx1 | ssh root@192.168.0.117 mysql -uroot -p12345678 gx_copy1
