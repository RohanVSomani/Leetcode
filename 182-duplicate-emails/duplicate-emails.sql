# Write your MySQL query statement below
#select distinct p1.email as Email from Person P1,Person P2 where p1.email = p2.email and p1.id !=p2.id
select email as Email from Person group by email having count(*)>1