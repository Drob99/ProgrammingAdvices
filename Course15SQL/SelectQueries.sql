-- select distinct
select DepartmentID from Employees;

select distinct DepartmentID from Employees;

select FirstName from Employees;
select distinct FirstName from Employees;

select FirstName, DepartmentID from Employees;
select distinct FirstName, DepartmentID from Employees;


-- where statements

select * from Employees
where Gendor = 'F';

select * from Employees
where MonthlySalary <= 500;

select * from Employees
where not MonthlySalary <= 500;

select * from Employees
where MonthlySalary > 500;

select * from Employees
where MonthlySalary < 500 and Gendor = 'F';

-- <> is NOT in SQL
select * from Employees
where CountryID <> 1;

select * from Employees
where DepartmentID = 1 OR DepartmentID = 2;

select * from Employees
where ExitDate is NULL;

select * from Employees
where ExitDate is not null;

-- "In" Operator

select * from Employees
where DepartmentID=1 Or DepartmentID=2;


select * from Employees
where DepartmentID=1 Or DepartmentID=2 or DepartmentID=7;


select * from Employees
where DepartmentID=1 Or DepartmentID=2 or DepartmentID=5 or DepartmentID=7;


select * from Employees
where DepartmentID in (1,2,5,7);


select * from Employees
where FirstName in ('Jacob','Brooks','Harper');


select Departments.Name from Departments 
where 
ID in ( select DepartmentID from Employees where MonthlySalary <=210 );


select Departments.Name from Departments 
where 
ID not in ( select DepartmentID from Employees where MonthlySalary <=210 );


-- Order By
select ID, FirstName,MonthlySalary from Employees
where DepartmentID=1


select ID, FirstName,MonthlySalary from Employees
where DepartmentID=1
Order By FirstName ;

select ID, FirstName,MonthlySalary from Employees
where DepartmentID=1
Order By FirstName ASC;

select ID, FirstName,MonthlySalary from Employees
where DepartmentID=1
Order By FirstName desc;

select ID, FirstName,MonthlySalary from Employees
where DepartmentID=1
Order By MonthlySalary ;


select ID, FirstName,MonthlySalary from Employees
where DepartmentID=1
Order By MonthlySalary Asc;


select ID, FirstName,MonthlySalary from Employees
where DepartmentID=1
Order By MonthlySalary Desc;



select ID, FirstName,MonthlySalary from Employees
where DepartmentID=1
Order By FirstName , MonthlySalary ;


select ID, FirstName,MonthlySalary from Employees
where DepartmentID=1
Order By FirstName ASC, MonthlySalary Desc;


-- Select Top Statement

Select * from Employees;


-- This will show top 5 employees.
Select top 5 * from Employees;


-- This will show top 10% of the data.
select top 10 percent * from Employees;

-- this will show the all salaries ordered from the heighest to lowest.
select  MonthlySalary from employees
order by MonthlySalary Desc;



-- this will show the all salaries ordered from the heighest to lowest without redundancy.
select distinct MonthlySalary from employees
order by MonthlySalary Desc;

-- this will show the heighest 3 salaries.
select  distinct  top 3 MonthlySalary from employees
order by MonthlySalary Desc;


--This will show all employees who takes one of the heighest 3 salaries.

select ID , FirstName, MonthlySalary from Employees where MonthlySalary In
(
	select  distinct  top 3 MonthlySalary from employees
	order by MonthlySalary Desc
)

Order By MonthlySalary Desc



--This will show all employees who takes one of the Lowest 3 salaries.
select ID , FirstName, MonthlySalary from Employees where MonthlySalary In
(
	select  distinct  top 3 MonthlySalary from employees
	order by MonthlySalary ASC
)

Order By MonthlySalary ASC



--Select As

Select A= 5 * 4 , B= 6/2 



Select A= 5 * 4 , B= 6/2 
from employees



Select ID, FirstName,  A = MonthlySalary/2
from employees


Select ID, FirstName + ' ' + LastName as FullName From Employees;


Select ID, FullName = FirstName + ' ' + LastName  From Employees;


select ID, FirstName , MonthlySalary , YealySalary = MonthlySalary * 12  from employees;


select ID, FirstName , MonthlySalary , YealySalary =MonthlySalary* 12 , BonusAmount= MonthlySalary * BonusPerc  from employees;


select Today = getDate()


select ID, FullName= FirstName + ' ' + LastName, Age = DATEDIFF(Year , DateOfBirth ,getDate()) from Employees;


-- between

select * from Employees
where (MonthlySalary >= 500 and MonthlySalary <= 1000);

select * from Employees
where MonthlySalary between 500 and 1000;

-- Count, avg, sum, min, max

select TotalCount = Count(MonthlySalary),
		TotalSum  = sum(MonthlySalary),
		Average  = avg(MonthlySalary),
		MinSalary  = min(MonthlySalary),
		MaxSalary  = max(MonthlySalary)

		from Employees;

select TotalCount = Count(MonthlySalary),
		TotalSum  = sum(MonthlySalary),
		Average  = avg(MonthlySalary),
		MinSalary  = min(MonthlySalary),
		MaxSalary  = max(MonthlySalary)

		from Employees where DepartmentID = 1;

select * from Employees;

select TotalEmployees = count(ID) from Employees;
select count(ExitDate) as ResignedEmployees from Employees;

-- Group By
select DepartmentID, TotalCount = Count(MonthlySalary),
		TotalSum  = sum(MonthlySalary),
		Average  = avg(MonthlySalary),
		MinSalary  = min(MonthlySalary),
		MaxSalary  = max(MonthlySalary)

		from Employees 
		group by DepartmentID
		order by DepartmentID;

-- Having
select DepartmentID, TotalCount = Count(MonthlySalary),
		TotalSum  = sum(MonthlySalary),
		Average  = avg(MonthlySalary),
		MinSalary  = min(MonthlySalary),
		MaxSalary  = max(MonthlySalary)

		from Employees 
		group by DepartmentID
		having Count(MonthlySalary) > 100
		order by DepartmentID;

-- case without having by making a virtual table in memory
select * from 
(
	select DepartmentID, TotalCount = Count(MonthlySalary),
			TotalSum  = sum(MonthlySalary),
			Average  = avg(MonthlySalary),
			MinSalary  = min(MonthlySalary),
			MaxSalary  = max(MonthlySalary)

			from Employees 
			group by DepartmentID
) R1
where R1.TotalCount > 100;


-- Like Statement
select * from Employees;

select ID, FirstName from Employees
where FirstName like 'a%';

select ID, FirstName from Employees
where FirstName like '%a';

select ID, FirstName from Employees
where FirstName like '%tell%';

select ID, FirstName from Employees
where FirstName like 'a%a';

-- second letter is a
select ID, FirstName from Employees
where FirstName like '_a%';

-- third letter is a
select ID, FirstName from Employees
where FirstName like '__a%';

-- starts with a and at least 3 chars // you can order by: order by len(FirstName) desc
select ID, FirstName from Employees
where FirstName like 'a__%';

-- at least 4 chars
select ID, FirstName from Employees
where FirstName like 'a___%';

select ID, FirstName from Employees
where FirstName like 'a%' or FirstName like 'b%';

------------------------------------------------------------------

-- Wild Cards
Update Employees
set FirstName = 'Mohammed', LastName = 'Abu-Hadhoud'
where ID = 285;

Update Employees
set FirstName = 'Mohammad', LastName = 'Maher'
where ID = 286;


select ID, FirstName, LastName from employees
where FirstName = 'Mohammed' or FirstName = 'Mohammad';

select ID, FirstName, LastName from Employees
where FirstName like 'Mohamm[ae]d';


select ID, FirstName, LastName from Employees
where FirstName not like 'Mohamm[ae]d';

select ID, FirstName, LastName from Employees
where FirstName like 'a%' or FirstName like 'b%' or FirstName like 'c%';


select ID, FirstName, LastName from Employees
where FirstName like '[abc]%';

-- start from a to l
select ID, FirstName, LastName from Employees
where FirstName like '[a-l]%';


