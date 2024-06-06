import java.util.Scanner;

// Custom exception for price less than 10
class TooMinAmount extends Exception {
    public TooMinAmount(String message) {
        super(message);
    }
}

// Custom exception for price greater than 20
class TooMaxAmount extends Exception {
    public TooMaxAmount(String message) {
        super(message);
    }
}

public class ProductPriceValidator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the product price: ");
        double price = scanner.nextDouble();

        try {
            validatePrice(price);
            System.out.println("Collect your product.");
        } catch (TooMinAmount | TooMaxAmount e) {
            System.out.println(e.getMessage());
        }
    }

    // Method to validate the price
    private static void validatePrice(double price) throws TooMinAmount, TooMaxAmount {
        if (price < 10) {
            throw new TooMinAmount("Error: The price is too low. Minimum amount should be 10.");
        } else if (price > 20) {
            throw new TooMaxAmount("Error: The price is too high. Maximum amount should be 20.");
        }
    }
}
