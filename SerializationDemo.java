import java.io.*;

// Step 1: Create a class that implements Serializable
class Note implements Serializable {
    private static final long serialVersionUID = 1L;
    private String title;
    private String content;

    public Note(String title, String content) {
        this.title = title;
        this.content = content;
    }

    @Override
    public String toString() {
        return "Note {\n\t\t" +
                "title='" + title + '\'' +
                ", \ncontent='" + content + '\'' +
                '}';
    }
}

public class SerializationDemo {
    public static void main(String[] args) {
        // Step 2: Serialize an object
        Note note = new Note("Java Serialization", "This is a note about Java Serialization and Deserialization.");
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("notes.ser"))) {
            oos.writeObject(note);
            System.out.println("Serialization Successful: " + note);
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Step 3: Deserialize the object
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream("notes.ser"))) {
            Note deserializedNote = (Note) ois.readObject();
            System.out.println("Deserialization Successful: " + deserializedNote);
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
