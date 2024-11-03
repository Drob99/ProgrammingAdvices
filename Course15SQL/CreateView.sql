create view ResignedEmployees as
select * from Employees
where ExitDate is Not NULL;

select * from ActiveEmployees
where ID = 285;

create view ActiveEmployees as
select * from Employees
where ExitDate is NULL;

create view ShortDetailedEmployees as
select ID, FirstName, LastName, Gendor 
from Employees;

