# Write your MySQL query statement below
# upadate Users
# # set name = (
#           select t.user_id,t.name from(
            select user_id,concat(ucase(substring(name,1,1)),lcase(substring(name,2))) as name
            from users
            order by user_id;
#           )t
#           order by t.user_id;
# # );