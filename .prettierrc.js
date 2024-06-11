// typescript
module.exports = {
  singleQuote: true,
  trailingComma: 'all',
  plugins: [
    'prettier-plugin-embed',
    'prettier-plugin-sql',
    'prettier-plugin-import-sort', // prettier-plugin-import-sort should be place after prettier-plugin-embed
  ],
  language: 'postgresql',
  keywordCase: 'upper',
  expressionWidth: 1000,
};
