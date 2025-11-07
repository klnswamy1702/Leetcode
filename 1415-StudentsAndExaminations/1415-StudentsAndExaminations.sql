-- Last updated: 07/11/2025, 13:42:33
# Write your MySQL query statement below


# SELECT student.student_id,student.student_name,subject.subject_name,COUNT(exam.subject_name) as attended_exams
# FROM Students as student
# JOIN Subjects as subject
# LEFT JOIN Examinations as exam
# ON student.student_id=exam.student_id AND subject.subject_name=exam.subject_name
# GROUP BY student.student_id,subject.subject_name
# ORDER BY student_id,subject_name;

# SELECT
#     Students.student_id,
#     Students.student_name,
#     Subjects.subject_name,
#     COUNT(Examinations.subject_name) AS attended_exams
# FROM Students
# JOIN Subjects
# LEFT JOIN Examinations
# ON Students.student_id = Examinations.student_id
# AND Subjects.subject_name = Examinations.subject_name
# GROUP BY Students.student_id, Subjects.subject_name
# ORDER BY student_id ASC, subject_name ASC



select st.student_id, st.student_name, sb.subject_name, count(e.subject_name) as attended_exams
from Students st
join Subjects sb
left join
examinations e
on e.student_id = st.student_id
and e.subject_name = sb.subject_name
group by st.student_id, sb.subject_name
order by st.student_id
