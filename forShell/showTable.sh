#! /bin/bash
mysql -uroot -p123456 -e "
use $1;
select * from $2 limit 50;
"
