module.exports = {
  root: true,
  env: {
    // https://eslint.org/docs/latest/use/configure/language-options#specifying-environments
    es2022: true, // adds all ECMAScript 2022 globals and automatically sets the ecmaVersion parser option to 13.
    node: true, // Node.js global variables and Node.js scoping.
    jest: true, // Jest global variables.
  },
  parser: '@typescript-eslint/parser',
  parserOptions: {
    // https://typescript-eslint.io/architecture/parser/
    project: true, // find the tsconfig.json nearest each source file
    tsconfigRootDir: __dirname, // provide the root directory for relative TSConfig paths specified in the project option
  },
  plugins: ['@typescript-eslint'],
  extends: [
    'eslint:recommended',
    'plugin:@typescript-eslint/recommended',
    'plugin:@typescript-eslint/recommended-requiring-type-checking',
    'plugin:@typescript-eslint/strict',
    'prettier',
  ],
  rules: {
    '@typescript-eslint/no-unused-vars': ['warn', { argsIgnorePattern: '^_' }],
    eqeqeq: [
      'error',
      'always',
      {
        null: 'ignore',
      },
    ],
    // https://typescript-eslint.io/rules/no-shadow/
    // Note: you must disable the base rule as it can report incorrect errors
    'no-shadow': 'off',
    '@typescript-eslint/no-shadow': 'error',
    '@typescript-eslint/no-unused-vars': ['warn', { ignoreRestSiblings: true }],
  },
};
