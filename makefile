#!/bin/bash

# Variables
BRANCH_NAME="branch1"
COMMIT_MESSAGE="Make file from git script"

# Function to add, commit, and push changes
git_add_commit_push() {
    # Add all modified and new files to the staging area
    git add .


    # Commit changes with a specified commit message
    git commit -m "$COMMIT_MESSAGE"

    # Push changes to the remote repository
    git push origin "$BRANCH_NAME"
}

# Main script execution
# Check if there are any changes to commit
if [[ -n $(git status -s) ]]; then
    # Call function to add, commit, and push changes
    git_add_commit_push
    echo "Changes committed and pushed successfully."
else
    echo "No changes to commit."
fi

