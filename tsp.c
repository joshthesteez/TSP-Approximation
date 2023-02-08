#include <stdio.h>
#define INT_MAX 999999
#define MIN(i, j) (((i) < (j)) ? (i) : (j))

int main() {
    /*
    // user input implementation
    // uncomment if you wish to manually populate the array, 
    // but you will have to account for double entries for cities
    printf("Enter number of cities: ");
    int n;
    scanf("%d", &n);
    
    // map of distances between each city
    int dist[n][n];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // diagonal entries are 0 by default 
            // (the distance between city 1 and itself is 0)
            if (i == j) {
                dist[i][j] = 0;
            }
            else {
                // displayed as i+1 and j+1 due to indexing
                // start with city 1 rather than city 0
                printf("Enter distance between city %d & %d: ", i+1, j+1);
                int city_dist;
                scanf("%d", &city_dist);
                dist[i][j] = city_dist;
            }

        }
    }
    */

    // number of cities
    int n = 4;
    printf("Enter upper bound \"B\": ");
    int B_bound;
    scanf("%d", &B_bound);
    
    // declare dp array    
    int dp[16][16];

    // initialize dp array
    for (int i = 0; i<(1<<n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    
    // if all cities have been visited
    int VISITED_ALL = (1<<n) - 1;

// hardcode implementation --> best implementation

// map of distance between cities
int dist[10][10] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}
};



//helper function -> implements the tsp algorithm
int tsp(int mask, int pos) {

    // BASE CASE -> when all cities are visited
    if(mask==VISITED_ALL) {
        return dist[pos][0];
    }
    
    // lookup
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    // attempt to visit an unvisited city
    for (int city = 0; city < n; city++) {

        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1<<city), city);
            ans = MIN(ans, newAns);
        }

    }

    return dp[mask][pos] = ans;

}

// adds extra parameter "B" to our tsp algorithm
// B -> upper bound for minimum weight solution
void tsp_with_B(int mask, int pos, int B) {
    
    if (tsp(mask, pos) < B) {
        printf("YES\n");
    }
    
    
    else {
        printf("NO\n");
    }
    
    
}
    // printf("%d\n", tsp(1, 0));
    tsp_with_B(1, 0, B_bound);
    return 0;
}
