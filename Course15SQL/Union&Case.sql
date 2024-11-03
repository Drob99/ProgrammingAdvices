select * from ActiveEmployees;

select * from ResignedEmployees;


select * from ActiveEmployees
Union
select * from ResignedEmployees;

-- removes duplication
select * from Departments
Union
select * from Departments;


-- union all gives all without removing duplication
select * from Departments
Union All
select * from Departments;



-- Case
select ID, FirstName, LastName, GenderTitle =
case
	when Gendor = 'M' then 'Male'
	when Gendor = 'F' then 'Female'
	else	'Unknown'
end

from Employees;


select ID, FirstName, LastName, GenderTitle =
case
	when Gendor = 'M' then 'Male'
	when Gendor = 'F' then 'Female'
	else	'Unknown'
end,

Status = 
case
	when ExitDate is Null then 'Active'
	when ExitDate is not null then 'Resigned'
end
from Employees;


select ID, FirstName, LastName, MonthlySalary,
NewSalaryToBe =
case
	when Gendor = 'M' then MonthlySalary * 1.1
	when Gendor = 'F' then MonthlySalary * 1.15
	else	'Unknown'
end

from Employees