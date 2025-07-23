import string

print("Welcome to our site!")
print("Please Create an Account and Password")

flag = False;
accountname = input("Please enter your account name: ")


feedback = {
    "length" : "Number of characters entered are too short",
    "uppercase" : "Please have more than 1 upper case in your password",
    "digit" : "Please have more than 1 digit in your password",
    "special character" : "Please add special characters in your password"
}



while(flag != True):

    password = input("Please enter your password: ");

    has_uppercase = any(char.isupper() for char in password)
    has_digit  = any(num.isdigit() for num in password)
    has_specialcharacter = any(spchar in string.punctuation  for spchar in password)
    
    if(len(password) < 8):
        print("Too weak")
        print(feedback["length"])
        print(feedback["uppercase"])
        print(feedback["digit"])
        print(feedback["special character"])
        flag = False
    elif not has_uppercase:
        print("Weak")
        print (feedback["uppercase"])
        flag = False
    elif not has_digit:
        print("Weak")
        print (feedback["digit"])
        flag = False
    elif not has_specialcharacter:
        print("Weak")
        print(feedback["special character"])
        flag = False
    else:
        flag = True
    print("\n")

print("\n")
print("Your account has been created successfully")
print("Account Name: ", accountname)
print("Password: [Hidden]")