create table user_information(
    user_id int,
	username varchar(50) not null,
	password varchar(20) not null,
	privledge int
);

create table nap_spots(
	id int unique not null,
	latitude decimal(10) not null,
	longitude decimal(10) not null,
	name varchar(20) not null,
	attribute_1 varchar(10),
	attribute_2 varchar(10),
	attribute_3 varchar(10),
	num_people int not null,
	description varchar(100),
	reserved int not null
);

create table favorites_list(
	id int unique not null,
    latitude decimal(10) not null,
    longitude decimal(10) not null,
    name varchar(20) not null,
    attribute_1 varchar(10),
    attribute_2 varchar(10),
    attribute_3 varchar(10),
    num_people int not null,
    description varchar(100),
    reserved int null
);
.separator ","
