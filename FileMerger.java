import java.io.*;

public class FileMerger {
    public static void main(String[] args) {
        // Files to be read
        File file1 = new File("f1.txt");
        File file2 = new File("f2.txt");
        
        // File to be written
        File mergedFile = new File("f3.txt");

        // Ensure f3.txt exists or create it
        try {
            if (!mergedFile.exists()) {
                mergedFile.createNewFile();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Use try-with-resources to ensure all streams are closed properly
        try (BufferedReader br1 = new BufferedReader(new FileReader(file1));
             BufferedReader br2 = new BufferedReader(new FileReader(file2));
             BufferedWriter bw = new BufferedWriter(new FileWriter(mergedFile))) {

            // Read content from first file and write to merged file
            String line;
            while ((line = br1.readLine()) != null) {
                bw.write(line);
                bw.newLine();
            }

            // Read content from second file and write to merged file
            while ((line = br2.readLine()) != null) {
                bw.write(line);
                bw.newLine();
            }

            System.out.println("Files merged successfully into f3.txt");

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
