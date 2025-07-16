print("===== TO DO LIST MANAGER =====")
print("1. Add Task")
print("2. View Task")
print("3. Delete Task")
print("4. Mark task as complete")
print("5. Exit")
print("===============================")

task = []
userchoice = int(input("Enter the task you want to perform: "))

while(userchoice < 1 or userchoice > 5):
    print("Invalid, enter a number between 1-5:")
    userchoice = int(input("Enter the task you want to perform (1-5): "))


while(userchoice != 5):
    if(userchoice == 1):
        taskNumber = int(input("How many number of tasks do you want to enter?: "))
        while(taskNumber < 0):
            print("Invalid make sure there are no negative number entered: ")
            taskNumber = int(input("How many number of tasks do you want to enter?: "))
        for i in range(taskNumber):
            task.append(input(f"Enter task {i + 1}: "))
    
    elif (userchoice == 2):
        if task:
            print("\nYour Current Tasks: ")
            for i, t in enumerate(task, 1):
                print(f'{i}.{t}')
        else: 
            print("No tasks in the list.")
        
    elif (userchoice == 3):
        if task:
            number_delete_task = int(input("How many tasks do you want to delete? "))
            for i in range(number_delete_task):
                delete_task = input("Enter the task you want to delete: ")
                if delete_task in task:
                    task.remove(delete_task)
                    print(f'Task {delete_task} has been deleted.')
                else:
                    print(f'Task {delete_task} not found.')
        else:
            print("No tasks to delete.")

    if(userchoice == 4):
        if task:
            number_task_completed = int(input("How many tasks have you completed? "))
            for i in range(number_task_completed):
                completed_task = input("Enter the task you completed: ")
                if completed_task in task:
                    print(f'Task {completed_task} has been completed.')
                else:
                    print(f'Task {completed_task} not found.')
        else:
            print("No tasks in to be marked as complete.")
    print("===== TO DO LIST MANAGER =====")
    print("1. Add Task")
    print("2. View Task") 
    print("3. Delete Task")
    print("4. Mark task as complete")
    print("5. Exit")
    print("===============================")

    task = []
    userchoice = int(input("Enter the task you want to perform: "))

    while(userchoice < 1 or userchoice > 5):
        print("Invalid, enter a number between 1-5:")
        userchoice = int(input("Enter the task you want to perform (1-5): "))    
print("To-Do-List App has exited. Thank you for using the App!")    
               
