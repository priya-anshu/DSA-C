import java.io.*;

public class PalindromeNumbers {

    public static void main(String[] args) {
        String numbersFile = "Number.txt";
        String palindromeFile = "palindromeOnly.txt";

        // Step 1: Create Number.txt file with numbers from 111 to 999
        createNumbersFile(numbersFile);

        // Step 2 and 3: Read the numbers and write palindromes to palindromeOnly.txt
        writePalindromesToFile(numbersFile, palindromeFile);
        
    }

    // Method to create Number.txt with numbers from 111 to 999
    private static void createNumbersFile(String fileName) {
        try (PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(fileName)))) {
            for (int i = 111; i <= 999; i++) {
                writer.println(i);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Method to write palindromic numbers to palindromeOnly.txt
    private static void writePalindromesToFile(String numbersFile, String palindromeFile) {
        try (BufferedReader reader = new BufferedReader(new FileReader(numbersFile));
             PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(palindromeFile)))) {

            String line;
            while ((line = reader.readLine()) != null) {
                int number = Integer.parseInt(line);
                if (isPalindrome(number)) {
                    writer.println(number);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Method to check if a number is a palindrome
    private static boolean isPalindrome(int number) {
        int original = number;
        int reverse = 0;

        while (number != 0) {
            int digit = number % 10;
            reverse = reverse * 10 + digit;
            number /= 10;
        }

        return original == reverse;
    }
}
