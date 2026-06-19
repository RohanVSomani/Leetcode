# Write your MySQL query statement below
with cte as (
    select D.name as Department, E.name as Employee, E.salary as Salary, dense_rank() over(partition by D.name order by E.salary desc) as ranks
    from Employee as E left join Department as D on D.id = E.departmentId
)

select Department , Employee , Salary from cte where ranks<=3 ;
