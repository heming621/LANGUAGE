#! /bin/bash

if [ $# -ne 3 ];then
  echo "Pls enter parameter: from_db, to_db, from_table";
  exit;
fi
mysql -uroot -p123456 -e "
use $2;
CREATE TABLE $3 AS (SELECT * FROM $1.$3 WHERE DATE_TIME > date_sub(date(now()),interval 3 month));
"

echo "Copy $1.$3 to $2.$3 successfully !";
