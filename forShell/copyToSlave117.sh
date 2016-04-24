#! /bin/bash
if [ $# -ne 3 ];then
  echo "Pls entern local_dbname, remote_host in formate hostname@IP, remote_dbname !"
  exit;
else
  mysqldump -uroot -p123456 $1 | ssh $2 mysql -uroot -p12345678 $3
fi
