# Task 2 notes

## Relationships
- `Student is-a Person`: public single inheritance.
- `Staff is-a Person`: public single inheritance.
- `TeachingAssistant is-a Student` and `is-a Staff`: public multiple inheritance; together this is hybrid inheritance.
- `ResearchScholar is-a Student`: public multilevel inheritance.
- Address/phone/course-like independent data can be modeled as member objects when they represent a has-a relationship.

## Diamond problem
Without virtual inheritance, `TeachingAssistant` contains two `Person` subobjects: one through `Student` and one through `Staff`. Accessing `name` can be ambiguous and the common base is duplicated. `virtual public Person` makes both paths share one virtual `Person` subobject. The most-derived `TeachingAssistant` constructor initializes that virtual base.

## Access table for a base member in Student
| Person member | public inheritance | protected inheritance | private inheritance |
|---|---|---|---|
| public | public | protected | private |
| protected | protected | protected | private |
| private | not directly accessible | not directly accessible | not directly accessible |

The provided code uses public inheritance for the is-a relationships. `Person` data is protected so derived classes can use it; callers use public member functions.

## Predict-before-run exercise
The virtual-inheritance program in the assignment prints `Person Student Staff TA` followed by a newline. With `virtual` removed, two `Person` base subobjects are constructed, so the sequence is `Person Student Person Staff TA`. Access to a shared `Person` member through a `TeachingAssistant` object becomes ambiguous unless qualified. Record the actual compiler output from your compiler.
