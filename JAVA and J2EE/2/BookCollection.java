import java.util.*;

public class BookCollection 
{

    public static void main(String[] args)
    {
        ArrayList<Book> al = new ArrayList<Book>();
        al.add(new Book("ced", "wer", "lmn", 1000.00));
        al.add(new Book("qqq", "aaa", "mmm", 5000.00));
        al.add(new Book("abc", "xyz", "pqr", 5000.00));
        ArrayList<Book> al1 = new ArrayList<Book>(al);
        Collections.sort(al1);
        System.out.println("***********Sorted Collection**********");
        for (Book b : al1) {
            System.out.println(b);
        }
        System.out.println("**********Original Collection**********");
        for (Book b : al) {
            System.out.println(b);
        }
    }
}
