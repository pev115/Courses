import java.util.Arrays;

public class IntSetDifference {
    
    private static final int    NUM_ARGS = 2;
    private static final int        SIZE = 0;
    private static final int      POINTS = 1;
    private static final int     ALG_ONE = 1;
    private static final int     ALG_TWO = 2;
    private static final String    USAGE 
        = "Usage: java IntSetDifference <initial size> <points>";
    private static final int REPS = 10;
    

    /**
     * Returns the set difference of A - B. A, B and the returned set are
     * all duplicate-free arrays of integers in ascending order.
     */
    public static int[] linearSetDiff(int[] A, int[] B) {
        // TODO - implement this method 
        return null;
    }
    
    /**
     * Returns the set difference of A - B. A, B and the returned set are
     * all duplicate-free arrays of integers in ascending order.
     */
    public static int[] naiveSetDiff(int[] A, int[] B) {
        // TODO - implement this method 
        return null;
    }


    public static void main(String[] args) {
        int[]      checkedArgs = Utils.parseIntArgs(args, NUM_ARGS, USAGE);
        int        points      = checkedArgs[POINTS];
        int        size        = checkedArgs[SIZE];
        double[][] results     = new double[points][3];
        
        int[] A, B;
        long start;
        for (int point = 0; point < points; point++) {
                       
            results[point][SIZE] = size;
            A = Utils.makeOrdSet(size);
            B = Utils.makeOrdSet(size);
            start = System.currentTimeMillis();
            for (int i = 0; i < REPS; i++) {
                naiveSetDiff(A, B);
            }
            results[point][ALG_ONE] = 
                    (System.currentTimeMillis() - start) / REPS;

            start = System.currentTimeMillis();
            for (int i = 0; i < REPS; i++) {
                linearSetDiff(A, B);
            }
            results[point][ALG_TWO] = 
                    (System.currentTimeMillis() - start) / REPS;

            size *= 2;
        }
        
        Utils.printTimingsTable(results, 
            new String[]{"N","Naive","Linear"});
    }
    
}
