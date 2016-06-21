-- Q1 returns (name,name,born_in)
SELECT person_a.name,
       person_b.name,
       person_a.born_in
FROM   person AS person_a,
       person AS person_b,
       person AS person_c
WHERE  person_a.name = person_c.father 
AND    person_b.name = person_c.mother
AND    person_a.born_in = person_b.born_in
;

-- Q2 returns (name)

;

-- Q3 returns (name,father,mother)

; 

-- Q4 returns (name)

;

-- Q5 returns (name)

;

-- Q6 returns (house,name,accession)

;

