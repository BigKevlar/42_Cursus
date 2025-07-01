import { useEffect } from 'react';
import { useLocation } from 'react-router-dom';
import { fetchUserProfile } from './getUserData';

const OAuthSuccess = () => {
  const location = useLocation();

  useEffect(() => {
    const processOAuth = async () => {
      const hash = location.hash.substring(1);
      const params = new URLSearchParams(hash);
      const token = params.get('token');

      if (token) {
        localStorage.setItem('token', token);
        const profileResponse = await fetchUserProfile();
        localStorage.setItem('username', profileResponse.username);
        window.location.href = '/menu';
      } else {
       window.location.href = '/login';
      }
    };

    processOAuth();
  }, [location]);

  return <div>Redirecting...</div>;
};

export default OAuthSuccess;