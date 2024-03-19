create table user_information(
	id int unique not null,
	first_name varchar(20) not null,
	last_name varchar(20) not null,
	email varchar(30) not null,
	username varchar(50) not null,
	password varchar(20) not null
);

create table nap_spot(
	id int unique not null,
	latitude decimal(10) not null,
	longitude decimal(10) not null,
	name varchar(20) not null,
	attribute_1 varchar(10),
	attribute_2 varchar(10),
	attribute_3 varchar(10),
	num_people int not null,
	description varchar(100)
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
    description varchar(100)
);
.separator ","
