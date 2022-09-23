# Write your MySQL query statement below
select name
from Customer
where not id IN (
        select id
        from Customer
        where referee_id=2

);