import java.util.Set;
import java.util.TreeSet;

public class Utils {

    /**
     * Parses an array of Strings into ints.
     */
    public static int[] parseIntArgs(
            String[] args, int required, String usage) {
        if (args.length != required) {
            System.out.print("Error! ");
            System.out.print("Program must be called with " + required); 
            System.out.println(" arguments.");
            System.out.println(usage);
            System.exit(1);
        }
        
        int[] parsed = new int[required];

        try {
            for (int i = 0; i < required; i++) {
                parsed[i] = Integer.parseInt(args[i]);
            }
        } catch (NumberFormatException e) {
            System.out.print("Error parsing arguments. ");
            System.out.println("Please enter " + required + " integers.");
            System.exit(1);
        }
        
        return parsed;
    }

    /**
     * Prints the contents of results in columns, using titles as the titles.
     */
    public static void printTimingsTable(double[][] results, String[] titles) {
        double[] record;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < titles.length; i++) { sb.append("%10s "); }
        sb.append("%n");
        
        System.out.printf(sb.toString(), (Object[]) titles);
        for (int i = 0; i < results.length; i++) {
            record = results[i];
            for(int j = 0; j < record.length; j++) {
                System.out.printf("%10.2f ", record[j]);
            }
            System.out.println();
        }
    }

    /**
     * Returns an array, of length size, containing a set of integers 
     * in ascending order.
     */
    public static int[] makeOrdSet(int size) {
        Set<Integer> s  = new TreeSet<Integer>();
        while (s.size() < size) {
            s.add((int) (Math.random() * Integer.MAX_VALUE));
        }
        
        int[] ordSet = new int[size];
        int i = 0;
        for (int elem: s) {
            ordSet[i++] = elem;
        }
        return ordSet;
    }

}
