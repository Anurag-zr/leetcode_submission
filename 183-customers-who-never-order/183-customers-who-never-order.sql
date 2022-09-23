# Write your MySQL query statement below
select name as Customers
from customers
where not id in( 
                select customerId
                from orders);