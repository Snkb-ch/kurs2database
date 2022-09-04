CREATE TABLE cafedra(
id1 serial primary key,
namec VARCHAR(20) UNIQUE,
zaved VARCHAR(255) UNIQUE,
number VARCHAR(255) UNIQUE,
cabinet INT UNIQUE
);

create TABLE disciplina(
id2 serial primary key,
named VARCHAR(20) UNIQUE,
cafedra INT  REFERENCES cafedra(id1),
formaotcheta VARCHAR(255),
Kurs VARCHAR(255),
 kolvospec int
);

select * from disciplina
CREATE TABLE spec(
id3 serial primary key,
names VARCHAR(20) UNIQUE,

formaobuch VARCHAR(255),
timeofstud VARCHAR(255)
);
create TABLE Szyaz(
id4 serial PRIMARY KEY,
disc INT  REFERENCES disciplina(id2),
spec INT REFERENCES spec(id3),
cod int UNIQUE,
timeofdisc int,
beginning int


);
ALTER TABLE Szyaz ADD CONSTRAINT a UNIQUE(disc, spec)
delete from Szyaz where disc = 5

INSERT INTO cafedra(namec,zaved, number, cabinet) VALUES (

'KB-2',
'smirnov PETR',
'81333221',
330
)
	INSERT INTO disciplina(named, cafedra,formaotcheta,kurs, kolvospec) VALUES (
	'math',
	4,
	'экз',
	'NO', 
	0
	)
INSERT INTO spec(names,formaobuch,timeofstud) VALUES (
'09.03.02',
'очная',
'4'
)

SELECT * FROM cafedra;

SELECT * FROM disciplina;

SELECT * FROM Szyaz;

SELECT * FROM spec;


  SELECT szyaz.cod, szyaz.timeofdisc, szyaz.beginning, spec.names, disciplina.named FROM szyaz 
                    RIGHT JOIN spec  ON CASE spec.id3 WHEN szyaz.spec THEN 1 ELSE 0 END = 1
                    RIGHT JOIN disciplina on case disciplina.id2
                    when szyaz.disc
                      THEN 1
                      ELSE 0
                   END = 1

	LEFT JOIN Szyaz ON disciplina.id2 = Szyaz.disc
create VIEW viewn AS
SELECT * FROM disciplina 
	RIGHT JOIN cafedra  ON CASE cafedra.id1
		WHEN disciplina.cafedra 
			THEN 1
			ELSE 0
			END = 1
update viewn set formaotcheta = 'çà÷åò',Kurs = 'no' WHERE id2 = 'math'
update viewn set  zaved = 'SMIRNOV', number = 377, cabinet = 111 where id2 =  'math'
SELECT * FROM viewn

SELECT *, (select zaved from cafedra where cafedra.id1 = disciplina.cafedra) as zaved from disciplina --ÊÎÐÅËßÖ+ÏÎÄÇÀÏÐÎÑ Â SELECT

SELECT id2 FROM (SELECT * FROM disciplina WHERE formaotcheta  = 'экз') as a

SELECT * FROM disciplina WHERE id2 in (SELECT disc FROM Szyaz where beginning = 1)


SELECT a.id1, a.zaved, a.number from cafedra a where 'yes' in 
( select b.Kurs from disciplina b where  b.cafedra = a.id1) -- êîðåëÿö 



SELECT disc, spec, (select cafedra from disciplina d  where d.id2 = s.disc) as cafedra, 
(select named from disciplina d  where d.id2 = s.disc)

from Szyaz s

SELECT disc, spec, (select cafedra from disciplina d  where d.id2 = s.disc)as cafedra ,

(select named from disciplina where id2 =s.disc) as namedisc 
from Szyaz s 




SELECT disc, formaotcheta from disciplina	 JOIN Szyaz ON disciplina.id2 = Szyaz.disc   GROUP BY disc, formaotcheta having MIN(timeofdisc) >1


SELECT * from Szyaz where timeofdisc >= all (select timeofdisc from Szyaz)

SELECT * from (select *from disciplina  join Szyaz on disciplina.id2 = Szyaz.disc) as a where timeofdisc > some (select timeofdisc from Szyaz where beginning>=2) --ñðîê îáó÷åíèÿ áîëüøå ëþáîãî ïðè íà÷àëå îáó÷åíèÿ ïîñëå 2 ñåìåñòðà

select * from disciplina where id2 = any (select disc from Szyaz)-- åñëè â ñâÿçè åñòü çàïèñü, ÷òî ïðåäìåò ïðåïîäàåòñÿ íà êàêîé ëèáî ñïåöèàëüíîñòè òî òî âûâîä äèñöèïëèíû



/*alter TRIGGER t1
ON disciplina after insert
as
begin

insert into Szyaz(cafedra) select inserted.cafedra from inserted, Szyaz where id2 = Szyaz.disc
end


create TRIGGER t2
ON Szyaz after delete
as
begin
if 1<select (COUNT(case disc when deleted.disc then 1 else 0 end)) from Szyaz
begin
DELETE FROM disciplina WHERE id2 = (select disc from deleted) 
end
end
delete from Szyaz where disc = 'c++' and spec = '09.03.02'
delete from disciplina where cod2 = 'c++'
*/
INSERT INTO Szyaz(disc,spec,cod,timeofdisc,beginning) VALUES (

14,
4,
	443,
1,
2
)
CREATE FUNCTION t1() 
RETURNS TRIGGER 
AS $$
BEGIN
UPDATE disciplina SET kolvospec = kolvospec+1 where id2 = NEW.disc;
RETURN NEW;
END;
$$ LANGUAGE plpgsql;

create trigger tr1 after insert
on szyaz 
for each ROW
EXECUTE PROCEDURE t1()
------

call inssz('history', '09.03.10','882','1','1')
-------------------
CREATE FUNCTION t2() 
RETURNS TRIGGER 
AS $$
BEGIN
UPDATE disciplina SET kolvospec = kolvospec-1 where id2 = OLD.disc;
RETURN NEW;
END;
$$ LANGUAGE plpgsql;

create trigger tr2 after DELETE
on szyaz 
for each ROW
EXECUTE PROCEDURE t2()
----------------
update disciplina set kolvospec = 0
create FUNCTION t3() 
RETURNS TRIGGER 
AS $$
BEGIN
--if ( Szyaz.disc !=  OLD.disc  AND id2 = NEW.disc)
--THEN

UPDATE disciplina SET kolvospec=kolvospec-1 where id2 = OLD.disc  ;
UPDATE disciplina SET kolvospec=kolvospec+1 where id2 = NEW.disc;
--END IF;
RETURN NEW;
END;
$$ LANGUAGE plpgsql;

create trigger tr3 after UPDATE
on szyaz 
for each ROW
EXECUTE PROCEDURE t3()


update Szyaz set disc = 2 where disc = 2 and spec = 1
update disciplina set kolvospec = 0 where id2 = 3 

--(select disc from Szyaz where disc = (select disc from inserted))



--where id2 = (select disc from inserted) and (id2 != (select disc from deleted) )



CREATE INDEX ind1 ON cafedra(namec)

SELECT namec, zaved FROM cafedra WHERE namec = 'ÊÁ-2'

CREATE PROCEDURE addcaf(
	v_namec VARCHAR(20),
	v_zaved VARCHAR(20),
	v_number INT,
	v_cabinet INT)
	LANGUAGE SQL
AS $$ 
INSERT INTO cafedra(namec, zaved, number, cabinet)
VALUES (v_namec, v_zaved, v_number, v_cabinet);
$$;
create PROCEDURE delcaf(
	v_id1 VARCHAR(20))
	LANGUAGE SQL
AS $$
DELETE FROM Szyaz WHERE disc in (select id2 from disciplina where cafedra = (select id1 from cafedra where namec = v_id1));
--DELETE FROM spec WHERE id3 in (select spec FROM Szyaz WHERE disc in (select id2 from disciplina where cafedra = @id1))

DELETE FROM disciplina WHERE cafedra = (select id1 from cafedra where namec = v_id1);
DELETE FROM cafedra WHERE namec = v_id1;
$$;

CREATE PROCEDURE updcaf(
	v_id1 VARCHAR(20),
	v_namec VARCHAR(20),
	v_zaved VARCHAR(20),
	v_number INT,
	v_cabinet INT)
	LANGUAGE SQL
	as $$
	update cafedra
	set namec = v_namec, zaved = v_zaved, number = v_number, cabinet = v_cabinet where v_id1 = namec
$$;

create PROCEDURE insdisc(
	
	vnamed VARCHAR(20),
	vcafedra VARCHAR(20),
	vformaotcheta VARCHAR(20),
	vKurs VARCHAR(20))
	LANGUAGE SQL
	as $$
	insert into disciplina(named, cafedra, formaotcheta,Kurs, kolvospec) 
	VAlues(vnamed, (select id1 from cafedra where namec = vcafedra),vformaotcheta, vKurs, 0);
$$;

select * from cafedra
	CREATE PROCEDURE upddisc(
	vid2 VARCHAR(20),
	vnamed VARCHAR(20),
	vcafedra INT,
	vformaotcheta VARCHAR(20),
	vKurs VARCHAR(20))
	LANGUAGE SQL
	as $$
	update disciplina
	set named = vnamed, cafedra = vcafedra, formaotcheta=vformaotcheta,Kurs = vKurs where vid2 = named
$$;

	create PROCEDURE deldisc(
	vid2 VARCHAR(20))
	LANGUAGE SQL
AS $$
DELETE FROM Szyaz WHERE disc = (select id2 from disciplina where named = vid2);
DELETE FROM disciplina WHERE named = vid2;
$$;
	create PROCEDURE delsz(
	vid4 INT)
	LANGUAGE SQL
AS $$
DELETE FROM Szyaz WHERE cod = vid4;
$$;


CREATE PROCEDURE updsz
	(
		vid4 int,
	vdisc VARCHAR(20),
	vspec VARCHAR(20),
		
	vtimeofdisc int,
	vbeginning int)
	LANGUAGE SQL
	as $$
	update Szyaz
	set disc = (select id2 from disciplina where named = vdisc),spec = (select id3 from spec where names = vspec),cod = vid4, timeofdisc=vtimeofdisc,beginning = vbeginning where cod = vid4
$$;
	CREATE PROCEDURE inssz
	(
	vdisc varchar(20),
	vspec varchar(20),
		vcod int,
	vtimeofdisc int,
	vbeginning int)
	LANGUAGE SQL
	as $$
	
	
	insert into Szyaz(disc, spec, cod, timeofdisc,beginning) VAlues((select id2 from disciplina where named = vdisc),(select id3 from spec where names = vspec),vcod, vtimeofdisc,vbeginning);
	
$$;

call inssz('math','09.03.02',444,2,2)
select * from szyaz
	CREATE PROCEDURE insspec(
	
	vnames VARCHAR(20),
	vformaobuch VARCHAR(20),
	vtimeofstud int)
LANGUAGE SQL
	as $$
	insert into spec(names, formaobuch, timeofstud) VAlues(vnames, vformaobuch, vtimeofstud);
$$;
	
	create PROCEDURE delspec(
	vid3 VARCHAR(20))
	LANGUAGE SQL
AS $$
DELETE FROM Szyaz WHERE spec = (select id3 from spec where names = vid3);
DELETE FROM spec WHERE names = vid3;
$$;
CREATE PROCEDURE updspec(
	vid3 VARCHAR(20),
		vnames VARCHAR(20),
	vformaobuch VARCHAR(20),
	vtimeofstud int)
	LANGUAGE SQL
	as $$
	update spec
	set names = vnames, formaobuch = vformaobuch, timeofstud = vtimeofstud where vid3 = names;
$$;



	call  insdisc( 'networks', 2, 'зачет', 'no');
 EXEC inssz 17, 2, 2,6

create function getsr(vdisc VARCHAR(20))
 RETURNS numeric(10,2)
 as $$
 declare vsr numeric(10,2);
 begin
	
	vsr = (SELECT AVG(timeofdisc) FROM Szyaz WHERE disc = (select id2 from disciplina where named = vdisc));
	RETURN vsr;
	end;
	$$ LANGUAGE plpgsql;
	
	
	
	select  "getsr"('networks')

create function selcafedra(vname VARCHAR(20))	

returns table(namec varchar,zaved varchar,number varchar ,cabinet int)
as $$

 select  namec,zaved,number,cabinet  from cafedra where namec = vname ;

$$ LANGUAGE sql;

select * from public.selcafedra('КБ-2')


create PROCEDURE updprk2(
vupdname varchar(20),
vid VARCHAR(20))
LANGUAGE PLPGSQL
as $$

DECLARE curs CURSOR FOR SELECT namec from  cafedra;
Did1 VARCHAR(20);
Damec VARCHAR(20);
begin

open curs  ;--for update of namec
LOOP
FETCH curs into  Did1;
exit when not found;

IF (Did1 = vid)
THEN
update cafedra set namec = vupdname where current of curs;--where id1 = vid; 
END IF;
--fetch curs into Did1

END LOOP;
close curs;

end;
$$;
select * from cafedra
call public.updprk2('KB-11', 'КБ-6')



CREATE ROLE admin WITH
	NOLOGIN
	SUPERUSER
	CREATEDB
	CREATEROLE
	INHERIT
	NOREPLICATION
	CONNECTION LIMIT -1
	PASSWORD '123';
CREATE ROLE guests WITH
	NOLOGIN
	NOSUPERUSER
	NOCREATEDB
	NOCREATEROLE
	INHERIT
	NOREPLICATION
	CONNECTION LIMIT -1;
	
create user user1;
	GRANT admin TO user1;
	create user usersel;
	GRANT guests TO usersel;
	
	ALTER ROLE usersel
	PASSWORD '123';
	ALTER ROLE user1
	PASSWORD '123';

grant select on spec to guests;
grant select on disciplina to guests;
grant select on Szyaz to guests;
grant select on cafedra to guests;





select * from szyaz
call delall(false)
create procedure delall(i boolean )
LANGUAGE plpgsql

as $$
 declare i2 boolean;
 
begin
i2=i;
--delete from disciplina
delete from szyaz;
if i2 = true then
commit;
else 
rollback;
end if;
end;

$$ ;

commit
rollback




INSERT INTO Szyaz(disc,spec,timeofdisc,beginning) VALUES (

9,
2,
1,
2
)
CREATE UNIQUE INDEX i2
    ON public.cafedra USING btree
    (namec)
;
CREATE INDEX i3
    ON public.disciplina USING hash
    (named)
;
select * from cafedra where namec = 'KB-3'

select * from disciplina

select * from spec











