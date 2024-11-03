RESTORE FILELISTONLY
FROM DISK = '..\Course17SQLProjects\SelfReferentialQueries\EmployeesDB.bak';


RESTORE DATABASE EmployeesDB
FROM DISK = '..\Course17SQLProjects\SelfReferentialQueries\EmployeesDB.bak'
WITH MOVE 'EmployeesDB' TO '..\Course17SQLProjects\SelfReferentialQueries\EmployeesDB.mdf',
     MOVE 'EmployeesDB_log' TO '..\Course17SQLProjects\SelfReferentialQueries\EmployeesDB_log.ldf';

