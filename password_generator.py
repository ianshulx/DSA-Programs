# List for secure passwords
securePasswords = (('s', '$'), ('and', '&'), ('a', '@'), ('i', '|'), ('o', '0'),
                   ('m', 'w'), ('t', 'tea'), ('c', 'see'), ('h', '#'), ('b', 'bees'),
                   ('x', '*'), ('5', 'S'), ('S', '5'), ('1', '!'), ('2', '@'), ('3', 'Σ'),('$', 's'),)

# Function for converting the week characters into strong characters
def securePassword(password):
    for a, b in securePasswords:
        password = password.replace(a, b)
    return password

# function 
if __name__ == '__main__':
    # Get a input password from the user
    password = input("Enter your password : ") 
    password = securePassword(password)   
    print(f"Your secure password is {password}")
