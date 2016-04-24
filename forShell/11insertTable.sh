#! /bin/bash

declare i 
for i in {1..5};do
mysql -uroot -p123456 -e "
use $1;
INSERT INTO $2 VALUES ("PdfsffP","John4",date_sub(date(now()),interval 1 month));
"
i=$($i+1)
done
