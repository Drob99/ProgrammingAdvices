-- join and inner join is exactly the same
select Customers.CustomerID, Customers.Name, Orders.Amount
from Customers 
inner join Orders 
on Customers.CustomerID = Orders.CustomerID;


-- left join and left outer join are the same
select Customers.CustomerID, Customers.Name, Orders.Amount
from Customers 
left outer join Orders 
on Customers.CustomerID = Orders.CustomerID;

-- right join
select Customers.CustomerID, Customers.Name, Orders.Amount
from Customers 
right outer join Orders 
on Customers.CustomerID = Orders.CustomerID;

-- full join
select Customers.CustomerID, Customers.Name, Orders.Amount
from Customers 
full outer join Orders 
on Customers.CustomerID = Orders.CustomerID;

