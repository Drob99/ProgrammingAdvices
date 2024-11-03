
--this will show all data in the table
select * from Employees;

-- this will create a new table named EmployeesCopy1 based on the selected coumns then it will copy the data from Employees table based on the condition provided
SELECT *
INTO EmpoyeesCopy1
FROM Employees;

select * from EmpoyeesCopy1;




-- this will create a new table named EmployeesCopy1 based on the selected coumns then it will copy the data from Employees table based on the condition provided
SELECT ID, Name
INTO EmpoyeesCopy2
FROM Employees;

select * from EmpoyeesCopy2;



-- this will create a new table named EmployeesCopy1 based on the selected coumns then it will 
--  copy the data from Employees table based on the condition provided which is false means no data will be copied
SELECT *
INTO EmpoyeesCopy3
FROM Employees 
where 5=6;

select * from EmpoyeesCopy3;