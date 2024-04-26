create table user_information(
    user_id int,
	username varchar(50) not null,
	password varchar(20) not null,
	privledge int,
	spot1 int,
	spot2 int,
	spot3 int,
	spot4 int,
	spot5 int
);

create table nap_spots(
    id int,
	name varchar(20) not null,
	attribute_1 varchar(10),
	attribute_2 varchar(10),
	attribute_3 varchar(10),
	image varchar(100),
	reserve varchar(10)
);

.separator ","
.mode csv
.import "CSV/users.csv" user_information
.import "CSV/nap_spots.csv" nap_spots