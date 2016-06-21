-- Q1 RA query given can be represented in the following way in ANSI SQL
SELECT DISTINCT
       person_a.name,
       person_b.name,
       person_a.born_in
FROM person AS person_a
JOIN person AS person_b
ON   person_a.born_in = person_b.born_in
JOIN person AS person_c
ON   person_c.father = person_a.name
AND person_c.mother = person_b.name
;  


-- Q2 returns (name)
SELECT   name
FROM     monarch
WHERE    coronation IS NULL
AND      house IS NOT NULL
ORDER BY name

;

-- Q3 returns (name,father,mother)
SELECT person_a.name,
       person_a.father,
       person_a.mother
FROM   person AS person_a
JOIN   person AS person_b
ON     person_b.name = person_a.father
AND    person_b.dod > person_a.dod
INTERSECT
SELECT person_a.name,
       person_a.father,
	        person_a.mother
FROM   person AS person_a
JOIN   person AS person_b
ON     person_b.name = person_a.mother
AND    person_b.dod > person_a.dod
ORDER BY  name
; 

-- Q4 returns (name)
SELECT   name 
FROM     monarch
WHERE    house IS NOT NULL
UNION 
SELECT   name
FROM     prime_minister
ORDER BY name
;


-- Q5 returns (name)
SELECT DISTINCT person.name 
FROM   person

JOIN   monarch AS monarch_a
ON     person.name = monarch_a.name
AND    monarch_a.house IS NOT NULL

JOIN   monarch AS monarch_b
ON    person.dod> monarch_b.accession 
AND   monarch_a.accession < monarch_b.accession
ORDER BY name
;


-- Q6 returns (house,name,accession)
SELECT monarch_a.name, monarch_a.house, monarch_a.accession
FROM monarch AS monarch_a
WHERE house IS NOT NULL
AND monarch_a.accession <= 
ALL
(
SELECT accession
FROM monarch as monarch_b
WHERE house IS NOT NULL
AND  monarch_b.house = monarch_a.house
)
ORDER BY accession

;

