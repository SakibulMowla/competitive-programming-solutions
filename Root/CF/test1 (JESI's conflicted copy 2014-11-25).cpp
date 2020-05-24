pair<int, int> CVideoBeautificationer::BeautificationFilter2(unsigned char *pBlurConvertingData, int iLen, int iHeight, int iWidth, int *effectParam)
{
	long long startSharpingTime = m_Tools.CurrentTimestamp();

	for (int i = 0; i <= iHeight; i++) {
		m_mean[i][0] = 0;
		m_variance[i][0] = 0;
	}
	memset(m_mean, iWidth, 0);
	memset(m_variance, iWidth, 0);


	for (int i = 1, iw = 0; i <= iHeight; i++, iw += iWidth)
	{
		int tmp = 0;
		for (int j = 1; j <= iWidth; j++)
		{
			tmp += pBlurConvertingData[i * iWidth + j - 1];
			m_mean[i][j] = tmp + m_mean[i - 1][j];

            if (i > 2 && j > 2) {
                int indx = m_mean[i][j] - m_mean[i - 3][j] - m_mean[i][j - 3] + m_mean[i - 3][j - 3];
                m_bufferr2[iw + j - 2] = m_precSharpness2[pBlurConvertingData[iw + j - 2]][indx];
            }
		}
	}

	int cur_pixel, tmp, tmp2;

	int totalYValue = 0;
	int yLen = iWidth * iHeight;
	int m_rr2 = 2 * m_radius;

	for (int i = 1, iw = 0; i <= iHeight; i++, iw += iWidth)
	{
		tmp = 0, tmp2 = 0;
		m_mean[i][0] = 0;

		for (int j = 1; j <= iWidth; j++)
		{
			totalYValue += pBlurConvertingData[iw + j - 1];

			cur_pixel = m_bufferr2[iw + j - 1];

			tmp += cur_pixel;
			m_mean[i][j] = tmp + m_mean[i - 1][j];

			tmp2 += m_square[cur_pixel];
			m_variance[i][j] = tmp2 + m_variance[i - 1][j];

			if (i > m_rr2 && j > m_rr2) {
                int miu = m_mean[i - m_rr2 - 1][j - m_rr2 - 1] + m_mean[i][j] - m_mean[i - m_rr2 - 1][j] - m_mean[i][j - m_rr2 - 1];
                int viu = m_variance[i - m_rr2 - 1][j - m_rr2 - 1] + m_variance[i][j] - m_variance[i - m_rr2 - 1][j]  - m_variance[i][j - m_rr2 - 1];

                double men = miu / m_pixels;
                double var = (viu - (miu * men)) / m_pixels;

                pBlurConvertingData[m_preIndex[i][j]] = min(255., max(0., pBlurConvertingData[m_preIndex[i][j]] + (m_sigma * men + var * m_bufferr2[m_preIndex[i][j]]) / (var + m_sigma)));
			}
		}
	}

	long long endSharpingTime = m_Tools.CurrentTimestamp();


	totalYValue = 0;
	yLen = iWidth * iHeight;

	for (int i = 1, iw = 0; i <= iHeight; i++, iw += iWidth)
	{
		tmp = 0, tmp2 = 0;
		m_mean[i][0] = 0;

		for (int j = 1; j <= iWidth; j++)
		{
			MakePixelBrightNew(&pBlurConvertingData[iw + j - 1]);

			totalYValue += pBlurConvertingData[iw + j - 1];
			MakePixelBright(&pBlurConvertingData[iw + j - 1]);

			cur_pixel = pBlurConvertingData[iw + j - 1];

			tmp += cur_pixel;
			m_mean[i][j] = tmp + m_mean[i - 1][j];

			tmp2 += m_square[cur_pixel];
			m_variance[i][j] = tmp2 + m_variance[i - 1][j];

			if (i > m_rr2 && j > m_rr2) {
                int miu = m_mean[i - m_rr2 - 1][j - m_rr2 - 1] + m_mean[i][j] - m_mean[i - m_rr2 - 1][j] - m_mean[i][j - m_rr2 - 1];
                int viu = m_variance[i - m_rr2 - 1][j - m_rr2 - 1] + m_variance[i][j] - m_variance[i - m_rr2 - 1][j]  - m_variance[i][j - m_rr2 - 1];

                double men = miu / m_pixels;
                double var = (viu - (miu * men)) / m_pixels;

                pBlurConvertingData[m_preIndex[i][j]] = min(255., max(0., (m_sigma * men + var * pBlurConvertingData[m_preIndex[i][j]]) / (var + m_sigma)));
			}
		}
	}

	long long endFilterTime = m_Tools.CurrentTimestamp();

	pair<int, int> result = { m_mean[iHeight][iWidth] / (iHeight*iWidth), m_variance[iHeight][iWidth] / (iHeight*iWidth) };
	return result;
}
