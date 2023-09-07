# Planner
```dataview
CALENDAR file.cday
```

# TODO
```dataviewjs
dv.taskList(dv.pages('#huiswerk').file.tasks.where(t => !t.completed));
```

# Gedaan
```dataviewjs
dv.taskList(dv.pages('#huiswerk').file.tasks.where(t => t.completed));
```