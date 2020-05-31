const createNode = function(value) {
  return { value, left: null, right: null };
};

const insertNode = function(tree, value) {
  if (tree === null) {
    return createNode(value);
  }

  if (tree.value > value) {
    tree.left = insertNode(tree.left, value);
    return tree;
  }
  tree.right = insertNode(tree.right, value);
  return tree;
};

const createTree = function(list) {
  return list.reduce(insertNode, null);
};

const printInOrder = function(tree) {
  if (tree === null) {
    return;
  }
  printInOrder(tree.left);
  console.log(tree.value);
  printInOrder(tree.right);
};

const search = function(tree, value) {
  if (tree === null) {
    return false;
  }

  if (tree.value === value) {
    return true;
  } 

  if (tree.value > value) {
    
    return search(tree.left, value);
  }
  return search(tree.right, value);
};

const main = function() {
  const list = [8, 10, 20, 1, 5, 9, 12, 6];
  const tree = createTree(list);
  console.log(tree);
  printInOrder(tree);
  console.log(search(tree, 9));
};

main();

    //       8
    // 1            10
    //  5       9       20
    //   6           12
