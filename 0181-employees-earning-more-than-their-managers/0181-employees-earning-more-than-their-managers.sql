# Write your MySQL query statement below
select A.name as Employee from Employee A where A.salary>(select b.salary from Employee b where b.id=A.managerId);