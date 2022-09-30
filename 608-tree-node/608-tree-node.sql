# # Write your MySQL query statement below
# select id,"Root" as type 
# from tree
# where p_id is null

# union

# select temp.id,"Inner" as type
# from (select t1.id 
#       from tree t1,tree t2
#       where t1.id = t2.p_id && t1.p_id is not NULL)temp
      
# UNION

# select id,"Leaf" as type 
# from tree
# where id not in (select t1.id
#                  from tree t1,tree t2
#                  where t1.id = t2.p_id);


# # SELECT id, 
# # (CASE WHEN (p_id IS NULL) THEN 'Root' 
# #  WHEN id NOT IN (SELECT distinct p_id FROM Tree ) THEN 'Leaf'    # A node is a leaf if it's not another leaf's parent
# #  ELSE 'Inner' END) AS type
# # FROM Tree
# # ORDER BY id ASC


select distinct t1.id,
case
when t1.p_id is null then "Root"
when t1.p_id is not null and t2.id is not null then "Inner"
when t1.p_id is not null and t2.id is null then "Leaf"
end as type
from tree t1
left join tree t2
on t1.id = t2.p_id;