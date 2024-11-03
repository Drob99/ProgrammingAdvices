-- Exploring the DB
use VehicleMakesDB;
select * from VehicleDetails;

select * from Makes;

select * from MakeModels;

select * from SubModels;

select * from Bodies;

select * from DriveTypes;

select * from FuelTypes;

-- SQL Queries Problems

--Problem 1: Create Master View

create view MyVehicleMasterDetails as 
select 
v.ID, v.MakeID, m.Make, v.ModelID, mm.ModelName, v.SubModelID, s.SubModelName, v.BodyID, b.BodyName,
v.Vehicle_Display_Name, v.Year, v.DriveTypeID, d.DriveTypeName, 
v.Engine, v.Engine_CC, v.Engine_Cylinders, v.Engine_Liter_Display, v.FuelTypeID, f.FuelTypeName, v.NumDoors
from VehicleDetails as v 
	join DriveTypes as d on v.DriveTypeID = d.DriveTypeID
	join Bodies as b on v.BodyID = b.BodyID
	join FuelTypes as f on v.FuelTypeID = f.FuelTypeID
	join MakeModels as mm on v.ModelID = mm.ModelID
	join Makes as m on v.MakeID = m.MakeID
	join SubModels as s on v.SubModelID = s.SubModelID;

-- or simply by the designer

select * from VehicleMasterDetails;

--Problem 2: Get all vehicles made between 1950 and 2000
select * from VehicleDetails where Year between 1950 and 2000;

--Problem 3: Get number of vehicles made between 1950 and 2000
select count(*) as NumberOfVehicles from VehicleDetails 
where Year between 1950 and 2000;

--Problem 4: Get number of vehicles made between 1950 and 2000 per make and order by num of vehicles desc
select Makes.make, count(*) as NumberOfVehicles from VehicleDetails
inner join Makes on VehicleDetails.MakeID = Makes.MakeID
where Year between 1950 and 2000 
group by Make
order by NumberOfVehicles desc;


--Problem 5: Get all makes that have manufactured more than 12000 vehicles between 1950 and 2000
select Makes.make, count(*) as NumberOfVehicles from VehicleDetails
inner join Makes on VehicleDetails.MakeID = Makes.MakeID
where Year between 1950 and 2000 
group by Make
having count(*) > 12000
order by NumberOfVehicles desc;

-- without having
select * from
(
select Makes.make, count(*) as NumberOfVehicles from VehicleDetails
inner join Makes on VehicleDetails.MakeID = Makes.MakeID
where Year between 1950 and 2000 
group by Make
) R1
where NumberOfVehicles > 12000
order by NumberOfVehicles desc;

--  Problem 6: Get number of vehicles made between 1950 and 2000 per make and add total vehicles column beside

select Makes.make, count(*) as NumberOfVehicles, TotalVehicles = (select count(*) from VehicleDetails)
from VehicleDetails
inner join Makes on VehicleDetails.MakeID = Makes.MakeID
where Year between 1950 and 2000 
group by Make
order by NumberOfVehicles desc;

-- Another way using join
select * from (
select Makes.Make, count(*) as NumbersOFVehicles  from VehicleDetails
Inner join Makes
on Makes.MakeID = VehicleDetails.MakeID
where Year between 1950 and 2000
group by Makes.Make
)R1
Inner join 
(select count(*) as TotalVehicle from VehicleDetails) R2
on 1 = 1
order by NumbersOFVehicles desc;

-- Problem 7: Get number of vehicles made between 1950 and 2000 per make and add total vehicles column beside it, then calculate it's percentage

select	Makes.make, 
		NumberOfVehicles = count(*), 
		TotalVehicles = (select count(*) from VehicleDetails),
		Perc = count(*) * 1.0 /  (select count(*) from VehicleDetails)
from VehicleDetails
inner join Makes on VehicleDetails.MakeID = Makes.MakeID
where Year between 1950 and 2000 
group by Make
order by NumberOfVehicles desc;

-- Abu Hadhoud's Way

select *, cast(NumberOfVehicles as float) / TotalVehicles as Perc from 
(
	select Makes.make, count(*) as NumberOfVehicles, TotalVehicles = (select count(*) from VehicleDetails)
	from VehicleDetails
	inner join Makes on VehicleDetails.MakeID = Makes.MakeID
	where Year between 1950 and 2000 
	group by Make
) R1
order by NumberOfVehicles desc;

-- Problem 8: Get Make, FuelTypeName and Number of Vehicles per FuelType per Make
select Makes.Make, FuelTypes.FuelTypeName, count(*) as NumberOfVehicles
from VehicleDetails
inner join Makes on VehicleDetails.MakeID = Makes.MakeID
inner join FuelTypes on VehicleDetails.FuelTypeID = FuelTypes.FuelTypeID
where VehicleDetails.Year between 1950 and 2000
group by Make, FuelTypeName
order by Make;

-- Problem 9: Get all vehicles that runs with GAS
select VehicleDetails.*, FuelTypes.FuelTypeName from
VehicleDetails inner join
FuelTypes on VehicleDetails.FuelTypeID = FuelTypes.FuelTypeID
where FuelTypeName = N'GAS'; -- N is for unicode chars

--  Problem 10: Get all Makes that runs with GAS
select distinct Makes.Make, FuelTypes.FuelTypeName from
VehicleDetails 
inner join
Makes on VehicleDetails.MakeID = Makes.MakeID
inner join
FuelTypes on VehicleDetails.FuelTypeID = FuelTypes.FuelTypeID
where FuelTypeName = N'GAS';

-- Problem 11: Get Total Makes that runs with GAS
select Count(distinct Makes.Make) as TotalMakesRunOnGas from
VehicleDetails 
inner join
Makes on VehicleDetails.MakeID = Makes.MakeID
inner join
FuelTypes on VehicleDetails.FuelTypeID = FuelTypes.FuelTypeID
where FuelTypeName = N'GAS';

--MAH's way
select count(*) as TotalMakesRunOnGas
from
(
	select distinct Makes.Make, FuelTypes.FuelTypeName from
	VehicleDetails 
	inner join
	Makes on VehicleDetails.MakeID = Makes.MakeID
	inner join
	FuelTypes on VehicleDetails.FuelTypeID = FuelTypes.FuelTypeID
	where FuelTypeName = N'GAS'
)R1;


--  Problem 12: Count Vehicles by make and order them by NumberOfVehicles from high to low
select Makes.Make, Count(*) as NumberOfVehicles
from VehicleDetails 
inner join
Makes on VehicleDetails.MakeID = Makes.MakeID
group by Make
order by NumberOfVehicles desc;

-- Problem 13: Get all Makes/Count Of Vehicles that manufactures more than 20K Vehicles
select Makes.Make, Count(*) as NumberOfVehicles
from VehicleDetails 
inner join
Makes on VehicleDetails.MakeID = Makes.MakeID
group by Make
having Count (*) > 20000
order by NumberOfVehicles desc;

-- Or without having
select * from
(
	select Makes.Make, Count(*) as NumberOfVehicles
	from VehicleDetails 
	inner join
	Makes on VehicleDetails.MakeID = Makes.MakeID
	group by Make
) R1
where NumberOfVehicles > 20000
order by NumberOfVehicles desc;

-- Problem 14: Get all Makes with make starts with 'B'
select Makes.Make from Makes where Make like 'B%';

-- Problem 15: Get all Makes with make ends with 'W'
select Makes.Make from Makes where Make like '%W';

-- Problem 16: Get all Makes that manufactures DriveTypeName = FWD
select distinct Makes.Make, DriveTypes.DriveTypeName from
VehicleDetails
inner join 
Makes on VehicleDetails.MakeID = Makes.MakeID
inner join
DriveTypes on VehicleDetails.DriveTypeID = DriveTypes.DriveTypeID
where 
DriveTypeName = 'FWD';

-- Problem 17: Get total Makes that Mantufactures DriveTypeName=FWD
select count(*) MakeWithFWD
from
(
select distinct Makes.Make, DriveTypes.DriveTypeName from
VehicleDetails
inner join 
Makes on VehicleDetails.MakeID = Makes.MakeID
inner join
DriveTypes on VehicleDetails.DriveTypeID = DriveTypes.DriveTypeID
where 
DriveTypeName = 'FWD'
) R1;

select count(distinct Makes.Make) as MakeWithFWD from
VehicleDetails
inner join 
Makes on VehicleDetails.MakeID = Makes.MakeID
inner join
DriveTypes on VehicleDetails.DriveTypeID = DriveTypes.DriveTypeID
where 
DriveTypeName = 'FWD';

-- Problem 18: Get total vehicles per DriveTypeName Per Make and order them per make asc then per total Desc
select distinct Makes.Make, DriveTypes.DriveTypeName, Count(*) as TotalVehicles
from
VehicleDetails 
inner join
Makes on VehicleDetails.MakeID = Makes.MakeID
inner join
DriveTypes on VehicleDetails.DriveTypeID = DriveTypes.DriveTypeID
group by Makes.Make, DriveTypes.DriveTypeName
order by make asc, TotalVehicles desc;

-- Problem 19: Get total vehicles per DriveTypeName Per Make then filter only results with total > 10,000
select distinct Makes.Make, DriveTypes.DriveTypeName, Count(*) as TotalVehicles
from
VehicleDetails 
inner join
Makes on VehicleDetails.MakeID = Makes.MakeID
inner join
DriveTypes on VehicleDetails.DriveTypeID = DriveTypes.DriveTypeID
group by Makes.Make, DriveTypes.DriveTypeName
having count(*) > 10000
order by make asc, TotalVehicles desc;


select * from 
(
	select distinct Makes.Make, DriveTypes.DriveTypeName, Count(*) as TotalVehicles
	from
	VehicleDetails 
	inner join
	Makes on VehicleDetails.MakeID = Makes.MakeID
	inner join
	DriveTypes on VehicleDetails.DriveTypeID = DriveTypes.DriveTypeID
	group by Makes.Make, DriveTypes.DriveTypeName
) R1
where TotalVehicles > 10000
order by make asc, TotalVehicles desc;


-- Problem 20: Get all Vehicles that number of doors is not specified
select * from VehicleDetails where NumDoors is NULL;

-- Problem 21: Get Total Vehicles that number of doors is not specified
select count(*) TotalWithNoSpecificDoors from VehicleDetails where NumDoors is NULL;

-- Problem 22: Get percentage of vehicles that has no doors specified
select cast(count(*) as float) / (select count(*) from VehicleDetails) PercOfNoSpecifiedDoors from VehicleDetails where NumDoors is NULL;

select 
	(
		CAST( (select count(*) from VehicleDetails where NumDoors is Null) as float)
		/
		Cast( (select count(*) from VehicleDetails) as float)
	) as PercOfNoSpecifiedDoors;

-- Problem 23: Get MakeID , Make, SubModelName for all vehicles that have SubModelName 'Elite'
select distinct VehicleDetails.MakeID, Makes.Make, SubModels.SubModelName 
from
VehicleDetails
inner join
Makes on VehicleDetails.MakeID = Makes.MakeID
inner join
SubModels on VehicleDetails.SubModelID = SubModels.SubModelID
where SubModels.SubModelName = 'Elite'
order by Makes.Make;


-- Problem 24: Get all vehicles that have Engines > 3 Liters and have only 2 doors
select * from VehicleDetails
where Engine_Liter_Display > 3 and NumDoors = 2;

-- Problem 25: Get make and vehicles that the engine contains 'OHV' and have Cylinders = 4
select Makes.Make, VehicleDetails.* from 
VehicleDetails
inner join
Makes on VehicleDetails.MakeID = Makes.MakeID
where VehicleDetails.Engine like '%OHV%' and VehicleDetails.Engine_Cylinders = 4;

-- Problem 26: Get all vehicles that their body is 'Sport Utility' and Year > 2020
select Bodies.BodyName, VehicleDetails.* 
from VehicleDetails
inner join
Bodies on VehicleDetails.BodyID = Bodies.BodyID
where Bodies.BodyName = 'Sport Utility' and VehicleDetails.Year > 2020;


-- Problem 27: Get all vehicles that their Body is 'Coupe' or 'Hatchback' or 'Sedan'
select Bodies.BodyName, VehicleDetails.* 
from VehicleDetails
inner join Bodies on VehicleDetails.BodyID = Bodies.BodyID
where Bodies.BodyName in ('Coupe', 'Hatchback', 'Sedan');

-- Problem 28: Get all vehicles that their body is 'Coupe' or 'Hatchback' or 'Sedan' and manufactured in year 2008 or 2020 or 2021
select Bodies.BodyName, VehicleDetails.* 
from VehicleDetails
inner join Bodies on VehicleDetails.BodyID = Bodies.BodyID
where Bodies.BodyName in ('Coupe', 'Hatchback', 'Sedan')
and VehicleDetails.Year in (2008, 2020, 2021);

-- Problem 29: Return found=1 if there is any vehicle made in year 1950
if exists (select top 1 * from VehicleDetails where Year = 1950)
	select found = 1;

select found=1 
where 
exists (
        select top 1 * from VehicleDetails where Year =1950
      )

-- Problem 30: Get all Vehicle_Display_Name, NumDoors and add extra column to describe number of doors by words, and if door is null display 'Not Set'
select distinct VehicleDetails.NumDoors from VehicleDetails;

select VehicleDetails.Vehicle_Display_Name, VehicleDetails.NumDoors, 
DoorDescription = 
CASE 
	when NumDoors = 0 then 'Zero Doors'
	when NumDoors = 1 then 'One Door'
	when NumDoors = 2 then 'Two Doors'
	when NumDoors = 3 then 'Three Doors'
	when NumDoors = 4 then 'Four Doors'
	when NumDoors = 5 then 'Five Doors'
	when NumDoors = 6 then 'Six Doors'
	when NumDoors = 8 then 'Eight Doors'
	when NumDoors is NULL then 'Not Set'
	else 'Unknown'
end
from
VehicleDetails;

-- Problem 31: Get all Vehicle_Display_Name, year and add extra column to calculate the age of the car then sort the results by age desc.
select VehicleDetails.Vehicle_Display_Name, VehicleDetails.Year,
		Age = YEAR(GETDATE()) - VehicleDetails.Year
from VehicleDetails
order by Age desc;

-- Problem 32: Get all Vehicle_Display_Name, year, Age for vehicles that their age between 15 and 25 years old
select VehicleDetails.Vehicle_Display_Name, VehicleDetails.Year,
	   YEAR(GETDATE()) - VehicleDetails.Year as Age
from VehicleDetails
where YEAR(GETDATE()) - VehicleDetails.Year between 15 and 25;

select * from
(
	select VehicleDetails.Vehicle_Display_Name, VehicleDetails.Year,
			Age = YEAR(GETDATE()) - VehicleDetails.Year
	from VehicleDetails
) R1
where Age between 15 and 25;


-- Problem 33: Get Minimum Engine CC , Maximum Engine CC , and Average Engine CC of all Vehicles
select min(VehicleDetails.Engine_CC) MinimumEngineCC, max(VehicleDetails.Engine_CC) MaximumEngineCC, avg(VehicleDetails.Engine_CC) AverageEngineCC
from VehicleDetails;

-- Problem 34: Get all vehicles that have the minimum Engine_CC
select VehicleDetails.Vehicle_Display_Name from VehicleDetails
where VehicleDetails.Engine_CC = (select min(VehicleDetails.Engine_CC) from VehicleDetails);

-- Problem 35: Get all vehicles that have the Maximum Engine_CC
select VehicleDetails.Vehicle_Display_Name from VehicleDetails
where VehicleDetails.Engine_CC = (select max(VehicleDetails.Engine_CC) from VehicleDetails);

-- Problem 36: Get all vehicles that have Engin_CC below average
select VehicleDetails.Vehicle_Display_Name from VehicleDetails
where VehicleDetails.Engine_CC < (select avg(VehicleDetails.Engine_CC) from VehicleDetails);

-- Problem 37: Get total vehicles that have Engin_CC above average
select Count(VehicleDetails.Vehicle_Display_Name) as NumberOfVehiclesAboveAverageEngineCC from VehicleDetails
where VehicleDetails.Engine_CC > (select avg(VehicleDetails.Engine_CC) from VehicleDetails);

select Count(*) as NumberOfVehiclesAboveAverageEngineCC from
(
 
	Select ID,VehicleDetails.Vehicle_Display_Name from VehicleDetails
	where Engine_CC > ( select avg(Engine_CC) as MinEngineCC  from VehicleDetails )

) R1

-- Problem 38: Get all unique Engine_CC and sort them Desc
select distinct VehicleDetails.Engine_CC
from VehicleDetails
order by Engine_CC desc;

-- Problem 39: Get the maximum 3 Engine CC
select distinct top 3 VehicleDetails.Engine_CC
from VehicleDetails
order by Engine_CC desc;

select distinct top 3 Engine_CC from VehicleDetails 
group by Engine_CC 
having Engine_CC <= max(Engine_CC)
order by  Engine_CC desc;

SELECT DISTINCT TOP 3 Engine_CC FROM VehicleDetails
WHERE  Engine_CC <= 
(SELECT MAX(Engine_CC) FROM VehicleDetails)
ORDER BY Engine_CC  DESC;

-- Problem 40: Get all vehicles that has one of the Max 3 Engine CC
select VehicleDetails.Vehicle_Display_Name from VehicleDetails 
where VehicleDetails.Engine_CC in 
(select distinct top 3 VehicleDetails.Engine_CC
from VehicleDetails
order by Engine_CC desc);

-- Problem 41: Get all Makes that manufactures one of the Max 3 Engine CC
select distinct Makes.Make from VehicleDetails
inner join
Makes on VehicleDetails.MakeID = Makes.MakeID
where VehicleDetails.Engine_CC in 
(select distinct top 3 VehicleDetails.Engine_CC
from VehicleDetails
order by Engine_CC desc)
order by make;

-- Problem 42: Get a table of unique Engine_CC and calculate tax per Engine CC
	-- 0 to 1000    Tax = 100
	-- 1001 to 2000 Tax = 200
	-- 2001 to 4000 Tax = 300
	-- 4001 to 6000 Tax = 400
	-- 6001 to 8000 Tax = 500
	-- Above 8000   Tax = 600
	-- Otherwise    Tax = 0

select distinct VehicleDetails.Engine_CC, 
Tax = 
case
	when VehicleDetails.Engine_CC between 0 and 1000 then 100
	when VehicleDetails.Engine_CC between 1001 and 2000 then 200
	when VehicleDetails.Engine_CC between 2001 and 4000 then 300
	when VehicleDetails.Engine_CC between 4001 and 6000 then 400
	when VehicleDetails.Engine_CC between 6001 and 8000 then 500
	when VehicleDetails.Engine_CC > 8000 then 600
	else 0
end
from VehicleDetails
order by VehicleDetails.Engine_CC; 

select Engine_CC,
	CASE
		WHEN Engine_CC between 0 and 1000 THEN 100
		 WHEN Engine_CC between 1001 and 2000 THEN 200
		 WHEN Engine_CC between 2001 and 4000 THEN 300
		 WHEN Engine_CC between 4001 and 6000 THEN 400
		 WHEN Engine_CC between 6001 and 8000 THEN 500
		 WHEN Engine_CC > 8000 THEN 600	
		ELSE 0
	END as Tax
from 
(
	select distinct Engine_CC from VehicleDetails
) R1
order by Engine_CC;

-- Problem 43: Get Make and Total Number Of Doors Manufactured Per Make
select Makes.Make, sum(VehicleDetails.NumDoors) TotalNumberOfDoors
from VehicleDetails
inner join
Makes on VehicleDetails.MakeID = Makes.MakeID
group by Makes.Make
order by TotalNumberOfDoors desc;

-- Problem 44: Get Total Number Of Doors Manufactured by 'Ford'
select Makes.Make, sum(VehicleDetails.NumDoors) TotalNumberOfDoors
from VehicleDetails
inner join
Makes on VehicleDetails.MakeID = Makes.MakeID
group by Makes.Make
having Makes.Make = 'Ford';

-- Problem 45: Get Number of Models Per Make
select Makes.Make, count(*) NumberOfModelsPerMake 
from MakeModels
inner join
Makes on MakeModels.MakeID = Makes.MakeID
group by Makes.Make
order by NumberOfModelsPerMake desc;


-- Problem 46: Get the highest 3 manufacturers that make the highest number of models
select top 3 * from
(
select Makes.Make, count(*) NumberOfModelsPerMake 
from MakeModels
inner join
Makes on MakeModels.MakeID = Makes.MakeID
group by Makes.Make
) R1
order by NumberOfModelsPerMake desc;

SELECT      top 3  Makes.Make, COUNT(*) AS NumberOfModels
FROM            Makes INNER JOIN
                         MakeModels ON Makes.MakeID = MakeModels.MakeID
GROUP BY Makes.Make
Order By NumberOfModels Desc

-- Problem 47: Get the highest number of models manufactured
select top 1 Makes.Make, count(*) NumberOfModelsPerMake 
from MakeModels
inner join
Makes on MakeModels.MakeID = Makes.MakeID
group by Makes.Make
order by NumberOfModelsPerMake desc;

select Max(NumberOfModels) as MaxNumberOfModels
from
(
		SELECT        Makes.Make, COUNT(*) AS NumberOfModels
		FROM            Makes INNER JOIN
								 MakeModels ON Makes.MakeID = MakeModels.MakeID
		GROUP BY Makes.Make
		
) R1;

-- Problem 48: Get the highest Manufacturers manufactured the highest number of models

select Makes.Make, Count(*) NumberOfModels from
Makes inner join
MakeModels on Makes.MakeID = MakeModels.MakeID
group by Makes.Make
having Count(*) =
(
select Max(NumberOfModels)
from
(
		SELECT  MakeModels.MakeID, COUNT(*) AS NumberOfModels
		FROM     MakeModels
		GROUP BY MakeModels.MakeID
		
) R1
);

-- Problem 49: Get the Lowest Manufacturers manufactured the lowest number of models
select Makes.Make, Count(*) NumberOfModels from
Makes inner join
MakeModels on Makes.MakeID = MakeModels.MakeID
group by Makes.Make
having Count(*) =
(
select Min(NumberOfModels)
from
(
		SELECT  MakeModels.MakeID, COUNT(*) AS NumberOfModels
		FROM     MakeModels
		GROUP BY MakeModels.MakeID
		
) R1
);

-- Problem 50: Get all Fuel Types , each time the result should be showed in random order
select * from FuelTypes
order by NEWID();


use EmployeesDB;

select * from Employees;

-- Problem 51: Get all employees that have manager along with Manager's name.
select Employees.Name, Employees.ManagerID, Employees.Salary, ManagerName = Managers.Name
from Employees
inner join
Employees as Managers on Employees.ManagerID = Managers.EmployeeID;

select *,
ManagerID = (select Employees.ManagerID from Employees where Employees.Name = vm.Name ) ,
ManagerName = (select Employees.Name from Employees where Employees.EmployeeID = (select Employees.ManagerID from Employees where Employees.Name = vm.Name ))
from
(select Employees.Name,Employees.Salary
from Employees
)vm
group by vm.Name,vm.Salary
having (select Employees.ManagerID from Employees where Employees.Name = vm.Name ) is not null
order by vm.Salary desc

-- Problem 52: Get all employees that have manager or does not have manager along with Manager's name, in case no manager name show null

select Employees.Name, Employees.ManagerID, Employees.Salary, ManagerName = Managers.Name
from Employees
left join
Employees as Managers on Employees.ManagerID = Managers.EmployeeID;

-- Problem 53: Get all employees that have manager or does not have manager along with Manager's name, 
-- in case no manager name the same employee name as manager to himself

select Employees.Name, Employees.ManagerID, Employees.Salary, ManagerName = 
case
	when Managers.Name is NULL then Employees.Name
	else Managers.Name
end
from Employees
left join
Employees as Managers on Employees.ManagerID = Managers.EmployeeID;

-- Problem 54: Get All Employees managed by 'Mohammed'
select Employees.Name, Employees.ManagerID, Employees.Salary, ManagerName = Managers.Name
from Employees
inner join
Employees as Managers on Employees.ManagerID = Managers.EmployeeID
where Managers.Name = 'Mohammed';




