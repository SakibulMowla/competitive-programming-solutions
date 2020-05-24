class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int intersection;
        if (A > G || E > C || B > H || F > D) {
            intersection = 0;
        } else {
            int xPart = max(0, min(G, C) - max(A, E));
            int yPart = max(0, min(H, D) - max(B, F));
            intersection = xPart * yPart;
        }
        return (C - A) * (D - B) + (G - E) * (H - F) - intersection;
    }
};
