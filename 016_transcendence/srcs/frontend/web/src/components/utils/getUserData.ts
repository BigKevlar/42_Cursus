import { useEffect, useState } from "react";

interface UserData {
  id: number;
  username: string;
}

interface ProfileResponse {
  message: string;
  id: string;
  user: string;
}

export const fetchUserProfile = async (): Promise<UserData> => {
  try {
    const response = await fetch("/api/auth/profile", {
      credentials: "include",
    });

    if (!response.ok) {
      if (response.status === 401) {
        window.location.href = "/login";
      }
      throw new Error(`HTTP error! status: ${response.status}`);
    }

    const data: ProfileResponse = await response.json();
    
    return {
      id: Number(data.id) || 0,
      username: data.user,
    };
  } catch (error) {
    if (error instanceof Error) {
      if (error.message.includes("Failed to fetch")) {
        throw new Error("Error de conexión al servidor");
      }
      throw error;
    }
    throw new Error("Error desconocido al obtener el perfil");
  }
};


const useProfile = () => {
  const [profile, setProfile] = useState<UserData | null>(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);

  useEffect(() => {
    const loadProfile = async () => {
      try {
        const data = await fetchUserProfile();
        setProfile(data);
        setError(null);
      } catch (err) {
        if (err instanceof Error) {
          setError(err.message);
        } else {
          setError("An unknown error occurred");
        }
        if (err instanceof Error && err.message.includes("401")) {
          setProfile(null);
        }
      } finally {
        setLoading(false);
      }
    };

    loadProfile();
  }, []);

  return { profile, loading, error };
};

export default useProfile;