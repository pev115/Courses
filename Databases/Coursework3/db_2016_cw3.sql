-- Q1 returns (first_name)
-- If only the first name is supplied then return it else extract the 
--first name from the full name supplied and return it. 
SELECT  DISTINCT
	CASE
	WHEN POSITION(' ' IN name) = 0
	THEN person.name
	ELSE
	SUBSTRING(name FROM 1 FOR POSITION(' ' IN name)-1) 
	END AS first_name
FROM person
ORDER BY first_name
;

-- Q2 returns (born_in,popularity)
-- Find the number of persons that are born in each place arrange it
-- in descending order
SELECT 
	born_in, 
	COUNT(born_in) AS popularity
FROM person
GROUP BY born_in
ORDER BY popularity DESC ,born_in
;


-- Q3 returns (house,seventeenth,eighteenth,nineteenth,twentieth)
-- Find the number of monarchs for each house for each of the relevant 
--senturies. 
SELECT 
	house,
	COUNT(CASE WHEN accession<'1700-01-01' 
	      THEN accession ELSE NULL END) AS seventeenth,
	COUNT(CASE WHEN accession<'1800-01-01' AND accession >'1700-01-01'
	      THEN accession ELSE NULL END) as eighteenth,
	COUNT(CASE WHEN accession<'1900-01-01'AND accession >'1800-01-01'
	      THEN accession ELSE NULL END) as nineteenth,
	COUNT(CASE WHEN accession<'2000-01-01' AND accession >'1900-01-01'
	      THEN accession ELSE NULL END) as twentieth
FROM monarch
WHERE house IS NOT NULL
GROUP BY house
ORDER BY house
; 


-- Q4 returns (name,age)
-- Fina all the names of all the people that are parents (i.e either father
-- or mother) and the age at which they had their first child.
SELECT 	person_b.name ,
		FLOOR((MIN(person_a.dob)-person_b.dob)/365.25) AS age
FROM person as person_a JOIN person as person_b 
ON person_a.father = person_b.name
GROUP BY person_b.name

UNION

SELECT 	person_b.name ,
		FLOOR((MIN(person_a.dob)-person_b.dob)/365.25) AS age
FROM person as person_a JOIN person as person_b 
ON person_a.mother = person_b.name
GROUP BY person_b.name

ORDER BY name
;




-- Q5 returns (father,child,born)
-- Find all the fathers and children of those fathers and rank the children for 
-- by date of birth
SELECT   person_a.name as father,
	 person_b.name as child,
	 CASE 
	 WHEN person_b.name IS NOT NULL
	 THEN RANK() OVER (PARTITION BY person_a.name ORDER BY person_b.dob) 
	 ELSE NULL END AS born
FROM person as person_a  LEFT JOIN person as person_b
ON  person_b.father = person_a.name
WHERE person_a.gender = 'M' 
;



-- Q6 returns (monarch,prime_minister)
-- Find the prime ministers that served under each monarch. There are two cases
-- to treat separately: the case where the prime minister's entry was after
-- the accession of the monarch and the case where the entry of the prime minister
-- was before the accesion of the monarch
SELECT DISTINCT monarch_a.name AS monarch ,prime_minister.name AS prime_minister
FROM monarch AS monarch_a JOIN prime_minister ON monarch_a.accession<prime_minister.entry 
AND prime_minister.entry< ALL( SELECT monarch_b.accession 
				FROM monarch AS monarch_b 
				WHERE monarch_b.accession> monarch_a.accession)
UNION

SELECT DISTINCT monarch.name AS monarch, prime_minister_a.name AS prime_minister
FROM monarch JOIN prime_minister AS prime_minister_a ON prime_minister_a.entry< monarch.accession
AND monarch.accession< ALL( SELECT prime_minister_b.entry
			   FROM prime_minister AS prime_minister_b
			   WHERE prime_minister_b.entry > prime_minister_a.entry)

ORDER BY monarch , prime_minister
;



