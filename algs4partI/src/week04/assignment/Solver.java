public class Solver {
    private Board initialBoard;
    private MinPQ<SolverStep> originPQ = new MinPQ<SolverStep>();
    private SolverStep solverStep = null;

    private Board twinBoard;
    private MinPQ<SolverStep> twinPQ = new MinPQ<SolverStep>();
    private boolean isSolvable = false;

    private class SolverStep implements Comparable<SolverStep> {
        private Board stepBoard;
        private SolverStep stepParent;
        private int stepMoves;
        private int stepManhattan;
        private int stepPriority;

        public SolverStep(Board board, int moves, SolverStep parent) {
            stepBoard = board;
            stepParent = parent;
            stepMoves = moves;
            stepManhattan = stepBoard.manhattan();
            stepPriority = stepMoves + stepManhattan;
        }

        public Board getStepBoard() {
            return stepBoard;
        }

        public void setStepBoard(Board board) {
            this.stepBoard = board;
        }

        public SolverStep getStepParent() {
            return stepParent;
        }

        public void setStepParent(SolverStep parent) {
            this.stepParent = parent;
        }

        public int getStepMoves() {
            return stepMoves;
        }

        public void setStepMoves(int moves) {
            this.stepMoves = moves;
        }

        public int getStepManhattan() {
            return stepManhattan;
        }

        public void setStepManhattan(int manhattan) {
            this.stepManhattan = manhattan;
        }

        public int getStepPriority() {
            return stepPriority;
        }

        public void setStepPriority(int priority) {
            this.stepPriority = priority;
        }

        public int compareTo(SolverStep that) {
            if (this.stepPriority < that.stepPriority) return -1;
            if (this.stepPriority > that.stepPriority) return 1;
            return 0;
        }
    }

    // find a solution to the initial board (using the A* algorithm)
    public Solver(Board initial) {
        initialBoard = initial;
        twinBoard = initialBoard.twin();
        SolverStep originStep = new SolverStep(initialBoard, 0, null);
        originPQ.insert(originStep);
        SolverStep twinStep = new SolverStep(twinBoard, 0, null);
        twinPQ.insert(twinStep);

        // A* algorithm
        while (true) {
            SolverStep currentOriginStep = originPQ.delMin();
            //StdOut.println(currentOriginStep.stepBoard.toString());
            //StdOut.println(currentOriginStep.stepPriority);
            if (currentOriginStep.stepBoard.isGoal()) {
                isSolvable = true;
                solverStep = currentOriginStep;
                break;
            } else {
                for (Board board : currentOriginStep.stepBoard.neighbors()) {
                    SolverStep newStep = new SolverStep(board,
                            currentOriginStep.stepMoves +1,
                            currentOriginStep);
                    if (newStep != currentOriginStep.stepParent)
                        originPQ.insert(newStep);
                }
            }

            SolverStep currentTwinStep = twinPQ.delMin();
            if (currentTwinStep.stepBoard.isGoal()) {
                break;
            } else {
                for (Board board : currentTwinStep.stepBoard.neighbors()) {
                    SolverStep newStep = new SolverStep(board,
                            currentTwinStep.stepMoves +1,
                            currentTwinStep);
                    if (newStep != currentOriginStep.stepParent)
                        twinPQ.insert(newStep);
                }
            }
        }

    }

    // is the initial board solvable?
    public boolean isSolvable() {
        return isSolvable;
    }

    // min number of moves to solve initial board; -1 if no solution
    public int moves() {
        if (!isSolvable())
            return -1;
        return solverStep.stepMoves;
    }

    // sequence of boards in a shortest solution; null if no solution
    public Iterable<Board> solution() {
        if (!isSolvable())
            return null;
        Stack<Board> boardSeq = new Stack<Board>();
        SolverStep step = solverStep;
        while (step != null) {
            boardSeq.push(step.stepBoard);
            step = step.stepParent;
        }
        return boardSeq;
    }

    // solve a slider puzzle (given below)
    public static void main(String[] args) {
        // create initial board from file
        In in = new In(args[0]);
        int N = in.readInt();
        int[][] blocks = new int[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                blocks[i][j] = in.readInt();
        Board initial = new Board(blocks);

        // solve the puzzle
        Solver solver = new Solver(initial);

        // print solution to standard output
        if (!solver.isSolvable())
            StdOut.println("No solution possible");
        else {
            StdOut.println("Minimum number of moves = " + solver.moves());
            for (Board board : solver.solution())
                StdOut.println(board);
        }
    }
}