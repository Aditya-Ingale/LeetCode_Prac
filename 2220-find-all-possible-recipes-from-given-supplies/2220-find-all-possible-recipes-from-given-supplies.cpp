class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> inDegree;  // Count of required ingredients for each recipe
        unordered_map<string, vector<string>> graph;  // Ingredient -> Recipes that depend on it
        unordered_set<string> available(supplies.begin(), supplies.end());  // Track available ingredients
        queue<string> q;
        vector<string> result;

        // Initialize graph and in-degree map
        for (int i = 0; i < recipes.size(); i++) {
            inDegree[recipes[i]] = ingredients[i].size();  // Number of ingredients required
            for (const string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);  // Ingredient ing is required by recipe[i]
            }
        }

        // Add all initial supplies to the queue
        for (const string& item : supplies) {
            q.push(item);
        }

        // Process the queue using BFS
        while (!q.empty()) {
            string item = q.front();
            q.pop();

            // If this item is a recipe, add it to the result
            if (inDegree.find(item) != inDegree.end()) {
                result.push_back(item);
            }

            // Reduce in-degree for recipes that require this ingredient
            for (const string& recipe : graph[item]) {
                if (--inDegree[recipe] == 0) {  // If all required ingredients are available
                    q.push(recipe);
                }
            }
        }

        return result;
    }
};