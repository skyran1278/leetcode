// @ts-check

import eslint from '@eslint/js';
import prettierConfig from 'eslint-config-prettier';
import globals from 'globals';
import tseslint from 'typescript-eslint';

export default tseslint.config(
  {
    ignores: ['eslint.config.mjs', '.prettierrc.js', 'node_modules', 'build'],
  },
  eslint.configs.recommended,

  // https://typescript-eslint.io/getting-started/typed-linting/#shared-configurations
  tseslint.configs.strictTypeChecked,
  tseslint.configs.stylisticTypeChecked,

  // https://typescript-eslint.io/users/what-about-formatting/#suggested-usage---prettier
  prettierConfig,

  {
    languageOptions: {
      globals: {
        ...globals.node,
        ...globals.jest,
      },
      // @see https://typescript-eslint.io/getting-started/typed-linting
      parserOptions: {
        projectService: true,
        tsconfigRootDir: import.meta.dirname,
      },
    },
  },
  {
    rules: {
      // https://eslint.org/docs/latest/rules/eqeqeq#allow-null
      eqeqeq: [
        'error',
        'always',
        {
          null: 'ignore',
        },
      ],

      // https://typescript-eslint.io/rules/no-shadow/
      'no-shadow': 'off',
      '@typescript-eslint/no-shadow': 'error',

      // https://eslint.org/docs/latest/rules/no-unused-vars#ignorerestsiblings
      // https://eslint.org/docs/latest/rules/no-unused-vars#argsignorepattern
      'no-unused-vars': 'off',
      '@typescript-eslint/no-unused-vars': [
        'warn',
        {
          argsIgnorePattern: '^_',
          ignoreRestSiblings: true,
        },
      ],
    },
  },
);
