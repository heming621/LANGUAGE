#! /bin/bash

if [ $# -ne 3 ];then
  echo "Pls enter parameter: from_db, to_db, from_table";
  exit;
fi

mysql -uroot -p123456 -e "
use $2;
INSERT INTO $2.$3 SELECT * FROM $1.$3 WHERE date > date_sub(date(now()),interval 3 month);
"

echo "Insert $1.$3 into $2.$3 successfully !";
