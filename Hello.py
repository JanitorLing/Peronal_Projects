def caesarCipher(text, key, mode='encrypt'):
    # Initialize an empty string to store the result
    result = ""
    # Ensure key stays within the range of 0-25
    key = key % 26  
    
    # If mode is 'decrypt', invert the key to shift in the opposite direction
    if mode == 'decrypt':
        key = -key

    # Iterate over each character in the input text
    for char in text:
        if char.isalpha():  # Check if the character is a letter
            # Determine the ASCII shift based on whether the character is uppercase or lowercase
            shift = ord('A') if char.isupper() else ord('a')
            # Shift the character within the alphabet and add it to the result string
            result += chr((ord(char) - shift + key) % 26 + shift)
        else:
            # Non-alphabetical characters remain unchanged
            result += char

    # Return the final result string
    return result

# Function to handle user interaction
def main():
    while True:
        # Get the mode from the user: 'e' for encrypt or 'd' for decrypt
        mode = input("Enter 'e' to encrypt or 'd' to decrypt: ").strip().lower()
        if mode not in ['e', 'd']:  # Validate user input
            print("Invalid option, please enter 'e' or 'd'.")
            continue
        
        # Get the text to be encrypted or decrypted
        text = input("Enter the text: ")
        # Get the key value from the user
        key = int(input("Enter the key (integer value): "))
        
        # Call the caesarCipher function with the appropriate mode
        result = caesarCipher(text, key, 'encrypt' if mode == 'e' else 'decrypt')
        # Display the result to the user
        print(f"\nThe {'encrypted' if mode == 'e' else 'decrypted'} text is: {result}\n")

        # Ask the user if they want to run the program again
        again = input("Do you want to run again? (yes/no): ").strip().lower()
        if again != 'yes':
            break

# Entry point of the program
if __name__ == "__main__":
    main()
