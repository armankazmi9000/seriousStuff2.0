select distinct(people.name) from people
join stars on people.id = stars.movie_id
join movies on stars.movie_id = movies.id
where movies.year = 2004
order by birth asc